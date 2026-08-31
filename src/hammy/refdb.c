#include <concord/log.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <hammy/refdb.h>

// Whole-callsign rules (cty.dat's "=CALL" entries) must match the entire string.
static const char SQL_EXACT[] =
    "SELECT e.id, e.name, e.continent,"
    "       COALESCE(p.cq_zone, e.cq_zone), COALESCE(p.itu_zone, e.itu_zone),"
    "       e.latitude, e.longitude, e.utc_offset, p.prefix"
    "  FROM dxcc_prefixes p JOIN dxcc_entities e ON e.id = p.entity_id"
    " WHERE p.prefix = ?1 AND p.exact = 1"
    " LIMIT 1";
 
// One candidate at a time, called longest-first by the caller.
static const char SQL_PREFIX[] =
    "SELECT e.id, e.name, e.continent,"
    "       COALESCE(p.cq_zone, e.cq_zone), COALESCE(p.itu_zone, e.itu_zone),"
    "       e.latitude, e.longitude, e.utc_offset, p.prefix"
    "  FROM dxcc_prefixes p JOIN dxcc_entities e ON e.id = p.entity_id"
    " WHERE p.prefix = ?1 AND p.exact = 0"
    " LIMIT 1";
 
static const char SQL_VERSION[] =
    "SELECT value FROM ref_meta WHERE key = 'bundle_version'";

static const char SQL_MORSE[] =
    "SELECT code FROM morse WHERE character = UPPER(?1) LIMIT 1";

// Band plus per-class privileges in one pass.
//
// Both LEFT JOINs matter. They are what makes "Technician: not permitted here"
// appear as a row rather than vanishing - a user excluded from a segment needs
// to be told so, not shown a shorter list.
//
// Boundary convention differs between the tables on purpose:
//   bands          inclusive at both ends. 14.350 is still "20m".
//   band_segments  half-open [low, high). 14.150 is the START of the phone
//                  segment, not the end of the CW one. BETWEEN would match
//                  both and the command would print contradictory modes.
static const char SQL_FREQ_MAIN[] =
    "SELECT b.name, b.edge_low_hz, b.edge_high_hz,"
    "       lc.code, lc.name, lc.rank,"
    "       s.modes, s.low_hz, s.high_hz, s.max_power_w, s.notes"
    "  FROM bands b"
    "  LEFT JOIN license_classes lc"
    "         ON lc.country = ?2"
    "  LEFT JOIN band_segments s"
    "         ON s.band_id  = b.id"
    "        AND s.class_id = lc.id"
    "        AND s.country  = ?2"
    "        AND s.low_hz  <= ?1"
    "        AND ?1         < s.high_hz"
    " WHERE b.edge_low_hz <= ?1 AND ?1 <= b.edge_high_hz"
    " ORDER BY lc.rank DESC, s.low_hz";
 
// Regional allocation, independent of national licensing. country = '' and
// class_id IS NULL mark these rows: they say what the band IS in a region, not
// who may use it.
static const char SQL_FREQ_IARU[] =
    "SELECT s.iaru_region, s.low_hz, s.high_hz, s.modes"
    "  FROM band_segments s"
    " WHERE s.country = '' AND s.class_id IS NULL"
    "   AND s.low_hz <= ?1 AND ?1 < s.high_hz"
    " ORDER BY s.iaru_region";
 
// min() with two arguments is SQLite's scalar min, not the aggregate.
static const char SQL_FREQ_NEAREST[] =
    "SELECT name, edge_low_hz, edge_high_hz,"
    "       min(abs(edge_low_hz - ?1), abs(edge_high_hz - ?1))"
    "  FROM bands ORDER BY 4 LIMIT 1";
 
// Is the frequency exactly on a segment boundary for this country?
static const char SQL_FREQ_SEG_EDGE[] =
    "SELECT 1 FROM band_segments"
    " WHERE country = ?2 AND (low_hz = ?1 OR high_hz = ?1) LIMIT 1";
 
static const char SQL_COUNTRY_LIST[] =
    "SELECT DISTINCT country FROM license_classes"
    " WHERE country <> '' ORDER BY country";

// Does the bundle carry licence data for this country at all? Only US is seeded
// so far, so "no data yet" is the common answer and needs saying properly.
static const char SQL_COUNTRY_KNOWN[] =
    "SELECT 1 FROM license_classes WHERE country = ?1 LIMIT 1";

// Authorizer: the connection may read, and nothing else.
//
// SQLITE_OPEN_READONLY protects the MAIN database file. It does not stop
// "ATTACH DATABASE 'somewhere.db' AS x" - an attached database is a separate
// file with its own flags, so a read-only connection is not automatically a
// read-only process. SQLITE_LIMIT_ATTACHED below closes that, and this
// authorizer closes it again, because defence in depth costs nothing here.
static int hammy_refdb_authorizer(void* unused, int action,
                                  const char* a1, const char* a2,
                                  const char* dbname, const char* trigger) {
    (void)unused; (void)a1; (void)a2; (void)dbname; (void)trigger;
 
    switch (action) {
        case SQLITE_SELECT:
        case SQLITE_READ:
        case SQLITE_FUNCTION:       // COALESCE, length(), upper() and friends
            return SQLITE_OK;
 
        default:
            // INSERT, UPDATE, DELETE, ATTACH, DETACH, CREATE/DROP anything,
            // PRAGMA, transactions - all refused at prepare time.
            return SQLITE_DENY;
    }
}

// Every prepared statement is registered in HAMMY_STATEMENTS below, exactly
// once. open() and close() both walk that table, so adding a statement means
// adding one row - not a struct field plus a prepare call plus a finalize call,
// three places that can silently drift apart.
//
// That drift is what produced the stCountryKnown crash: the field and the SQL
// existed, the prepare didn't, and sqlite3_clear_bindings() dereferenced a NULL
// left over from calloc(). Now it's impossible to reach a slot except through
// the table.
// NOTE: the SQL_* constants above are declared `static const char X[]`, not
// `static const char* X`. A pointer variable is not a constant expression, so
// using one in this table's static initializer is a compile error
// ("initializer element is not constant"). An array's address is a link-time
// constant and works. Don't "tidy" them back into pointers.
typedef struct {
    const char* name;       // for log messages
    size_t offset;          // into struct hammy_refdb_t
    const char* sql;
} hammy_stmt_def_t;

#define HAMMY_STMT(field, sqlConst) \
    { #field, offsetof(struct hammy_refdb_t, field), sqlConst }

static const hammy_stmt_def_t HAMMY_STATEMENTS[] = {
    HAMMY_STMT(stExact,        SQL_EXACT),
    HAMMY_STMT(stPrefix,       SQL_PREFIX),
    HAMMY_STMT(stMorse,        SQL_MORSE),
    HAMMY_STMT(stFreqMain,     SQL_FREQ_MAIN),
    HAMMY_STMT(stFreqIaru,     SQL_FREQ_IARU),
    HAMMY_STMT(stFreqNearest,  SQL_FREQ_NEAREST),
    HAMMY_STMT(stFreqSegEdge,  SQL_FREQ_SEG_EDGE),
    HAMMY_STMT(stCountryKnown, SQL_COUNTRY_KNOWN),
    HAMMY_STMT(stCountryList,  SQL_COUNTRY_LIST),
};

#define HAMMY_STMT_COUNT (sizeof(HAMMY_STATEMENTS) / sizeof(HAMMY_STATEMENTS[0]))

static sqlite3_stmt** stmt_slot(hammy_refdb_t* db, const hammy_stmt_def_t* def) {
    return (sqlite3_stmt**)((char*)db + def->offset);
}

// sqlite3_reset(NULL) is harmless, but sqlite3_clear_bindings(NULL) dereferences
// straight away. Query entry points check their statements before touching them,
// so a half-built refdb returns false instead of taking the process down.
static bool stmts_ready(const char* where, sqlite3_stmt* const* stmts, size_t count) {
    for (size_t i = 0; i < count; i++) {
        if (!stmts[i]) {
            log_error("[refdb] %s called with unprepared statements", where);
            return false;
        }
    }

    return true;
}

static bool prepare(sqlite3* h, const char* sql, sqlite3_stmt** out) {
    if (sqlite3_prepare_v2(h, sql, -1, out, NULL) != SQLITE_OK) {
        log_error("[refdb] prepare failed: %s", sqlite3_errmsg(h));
        log_error("[refdb]   sql: %s", sql);

        // prepare_v2 doesn't reliably clear this on every error path, and a
        // garbage pointer would sail past the NULL checks below.
        *out = NULL;

        return false;
    }

    return true;
}

hammy_refdb_t* hammy_refdb_open(const char* path) {
    if (!path) { return NULL; }

    hammy_refdb_t* db = (hammy_refdb_t*)calloc(1, sizeof(*db));
    if (!db) { return NULL; }

    // immutable=1 promises SQLite the fill won't change while it's open. Skips locks and change-counter checks
    // Faster and stricter than plain read-only
    char uri[1024];
    snprintf(uri, sizeof(uri), "file:%s?mode=ro&immutable=1", path);

    // NOMUTEX - exactly one thread uses this handle, avoid serialization overhead. Safe only because of the one-per-thread rule.
    int flags = SQLITE_OPEN_READONLY | SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_URI;

    if (sqlite3_open_v2(uri, &db->handle, flags, NULL) != SQLITE_OK) {
        log_error("[refdb] cannot open %s: %s", path, db->handle ? sqlite3_errmsg(db->handle) : "out of memory");
        goto fail;
    }

    // No ATTACH; closes a way a read-only connection could still open writable files.
    sqlite3_limit(db->handle, SQLITE_LIMIT_ATTACHED, 0);

    // Bound the damage of a pathological query. Turns a runaway into an error instead of a stall. Keeps plenty of headroom for actual lookups.
    sqlite3_limit(db->handle, SQLITE_LIMIT_SQL_LENGTH, 8192);
    sqlite3_limit(db->handle, SQLITE_LIMIT_EXPR_DEPTH, 100);
    sqlite3_limit(db->handle, SQLITE_LIMIT_LIKE_PATTERN_LENGTH, 256);
    sqlite3_limit(db->handle, SQLITE_LIMIT_VARIABLE_NUMBER, 32);

    // Refuse schema-corrupting tricks (e.g. PRAGMA writable_schema) and stop the schema itself from invoking unvetted functions.
    sqlite3_db_config(db->handle, SQLITE_DBCONFIG_DEFENSIVE, 1, NULL);
    sqlite3_db_config(db->handle, SQLITE_DBCONFIG_TRUSTED_SCHEMA, 0, NULL);

    // The bundle is small enough to just map memory-whole. Avoids a read() per page. Set before authorizer since it denies PRAGMA.
    sqlite3_exec(db->handle, "PRAGMA mmap_size = 67108864;", NULL, NULL, NULL);

    // TODO: PLEASE chmod 444 OR SOMETHING AND DON'T RUN AS THE SQLITE DB FILE OWNER - THAT'S THE ONLY REAL PROTECTION

    sqlite3_set_authorizer(db->handle, &hammy_refdb_authorizer, NULL);

    for (size_t i = 0; i < HAMMY_STMT_COUNT; i++) {
        const hammy_stmt_def_t* def = &HAMMY_STATEMENTS[i];

        if (!prepare(db->handle, def->sql, stmt_slot(db, def))) {
            log_error("[refdb] statement '%s' failed to prepare", def->name);
            goto fail;
        }
    }

    // Belt and braces. A registry that drifts from the struct would otherwise
    // leave a NULL slot that crashes inside SQLite on first use, far from the
    // cause. Fail here instead, naming the statement.
    for (size_t i = 0; i < HAMMY_STMT_COUNT; i++) {
        if (!(*stmt_slot(db, &HAMMY_STATEMENTS[i]))) {
            log_error("[refdb] statement '%s' is NULL after prepare", HAMMY_STATEMENTS[i].name);
            goto fail;
        }
    }

    sqlite3_stmt* st = NULL;
    if (prepare(db->handle, SQL_VERSION, &st)) {
        if (sqlite3_step(st) == SQLITE_ROW) {
            const unsigned char* v = sqlite3_column_text(st, 0);
            if (v) {
                snprintf(db->version, sizeof(db->version), "%s", (const char*)v);
            }
        }

        sqlite3_finalize(st);
    }
    
    return db;

fail:
    hammy_refdb_close(&db);
    return NULL;
}

bool hammy_refdb_close(hammy_refdb_t** db) {
    if (!db || !(*db)) { return false; }

    hammy_refdb_t* d = *db;

    // Statements must be finalized before the connection closes, or we're in deep shit
    // (sqlite3_close() returns SQLITE_BUSY and the handle leaks)
    for (size_t i = 0; i < HAMMY_STMT_COUNT; i++) {
        sqlite3_stmt** slot = stmt_slot(d, &HAMMY_STATEMENTS[i]);

        if (*slot) {
            sqlite3_finalize(*slot);
            *slot = NULL;
        }
    }
    
    if (d->handle) { sqlite3_close(d->handle); }

    free(d);
    *db = NULL;

    return true;
}

const char* hammy_refdb_version(hammy_refdb_t* db) {
    return (db && db->version[0]) ? db->version : NULL;
}

// Uppercase, strip whitespace, keep only characters that appear in callsigns (voodoo).
static void normalise(const char* in, char* out, size_t cap) {
    size_t j = 0;
 
    for (size_t i = 0; in[i] && j + 1 < cap; i++) {
        unsigned char c = (unsigned char)in[i];
 
        if (c >= 'a' && c <= 'z') { c = (unsigned char)(c - 'a' + 'A'); }
 
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '/') {
            out[j++] = (char)c;
        }
    }
 
    out[j] = '\0';
}

static void fill(sqlite3_stmt* st, hammy_dxcc_t* out, bool exact) {
    out->entityId = sqlite3_column_int(st, 0);
 
    const unsigned char* name = sqlite3_column_text(st, 1);
    const unsigned char* cont = sqlite3_column_text(st, 2);
    const unsigned char* pfx = sqlite3_column_text(st, 8);
 
    snprintf(out->name, sizeof(out->name), "%s", name ? (const char*)name : "");
    snprintf(out->continent, sizeof(out->continent), "%s", cont ? (const char*)cont : "");
    snprintf(out->matchedPrefix, sizeof(out->matchedPrefix), "%s", pfx ? (const char*)pfx : "");
 
    out->cqZone = sqlite3_column_int(st, 3);
    out->ituZone = sqlite3_column_int(st, 4);
    out->latitude = sqlite3_column_double(st, 5);
    out->longitude = sqlite3_column_double(st, 6);
    out->utcOffset = sqlite3_column_double(st, 7);
    out->exact = exact;
}

// Runs one candidate against a prepared statement. Returns true on a hit.
static bool try_one(sqlite3_stmt* st, const char* candidate, size_t len, hammy_dxcc_t* out, bool exact) {
    sqlite3_reset(st);
    sqlite3_clear_bindings(st);
    sqlite3_bind_text(st, 1, candidate, (int)len, SQLITE_STATIC);
 
    bool hit = (sqlite3_step(st) == SQLITE_ROW);
    if (hit) { fill(st, out, exact); }
 
    sqlite3_reset(st);
 
    return hit;
}
 
// Longest-first prefix search over one string.
static bool search_prefixes(hammy_refdb_t* db, const char* call, hammy_dxcc_t* out) {
    size_t len = strlen(call);
 
    for (size_t n = len; n > 0; n--) {
        if (try_one(db->stPrefix, call, n, out, false)) { return true; }
    }
 
    return false;
}

bool hammy_refdb_dxcc(hammy_refdb_t* db, const char* callsign, hammy_dxcc_t* out) {
    if (!db || !callsign || !out) { return false; }

    sqlite3_stmt* const needed[] = { db->stExact, db->stPrefix };
    if (!stmts_ready("dxcc", needed, 2)) { return false; }
 
    char call[HAMMY_CALLSIGN_MAX];
    normalise(callsign, call, sizeof(call));
 
    if (!call[0]) { return false; }
 
    memset(out, 0, sizeof(*out));
 
    // 1. Whole-callsign rules win outright. cty.dat carries a couple of thousand
    //    of these for stations that do not follow their entity's prefix pattern.
    if (try_one(db->stExact, call, strlen(call), out, true))
        return true;
 
    // 2. Portable designators. "DL/W1AW" is Germany, "W1AW/4" is still the US.
    //    The rule of thumb is that the SHORTER side of the slash is the location
    //    indicator, and a purely numeric tail is a call-area change rather than
    //    an entity change.
    //
    //    This is a heuristic, not a specification - real callsign parsing has
    //    genuine ambiguities and every logging program handles them slightly
    //    differently. Good enough for a lookup command; revisit before using it
    //    to award DXCC credit. TODO
    const char* slash = strchr(call, '/');
    if (slash) {
        char left[HAMMY_CALLSIGN_MAX] = {0};
        char right[HAMMY_CALLSIGN_MAX] = {0};
 
        size_t llen = (size_t)(slash - call);
        snprintf(left, sizeof(left), "%.*s", (int)llen, call);
        snprintf(right, sizeof(right), "%s", slash + 1);
 
        bool right_numeric = true;
        for (const char* p = right; *p; p++) {
            if (*p < '0' || *p > '9') {
                right_numeric = false;
                break;
            }
        }
 
        // A numeric tail keeps the home entity: try the left side only.
        if (right_numeric && right[0]) { return search_prefixes(db, left, out); }
 
        // Otherwise the shorter side is the location indicator.
        const char* location = (strlen(right) && strlen(right) < llen) ? right : left;
        const char* fallback = (location == right) ? left : right;
 
        if (search_prefixes(db, location, out)) { return true; }
 
        return search_prefixes(db, fallback, out);
    }
 
    // 3. Plain callsign: longest prefix wins.
    return search_prefixes(db, call, out);
}

bool hammy_refdb_get_morse(hammy_refdb_t* db, char c, const char** out) {
    if (!db || !out) { return false; }

    sqlite3_stmt* const needed[] = { db->stMorse };
    if (!stmts_ready("morse", needed, 1)) { return false; }

    // The table is ASCII (ITU-R M.1677-1 has no non-Latin extensions), and a
    // single byte out of a multi-byte UTF-8 sequence is not valid text to bind,
    // so anything with the high bit set is a miss without touching SQLite.
    if ((unsigned char)c & 0x80u) { return false; }

    // Run the query with the character as a string. SQLite's UPPER() handles case-insensitivity.
    // SQLITE_STATIC is safe because the statement is reset before this returns,
    // so key never outlives the binding that points at it.
    char key[2] = { c, '\0' };

    sqlite3_reset(db->stMorse);
    sqlite3_clear_bindings(db->stMorse);
    sqlite3_bind_text(db->stMorse, 1, key, 1, SQLITE_STATIC);

    bool hit = false;

    if (sqlite3_step(db->stMorse) == SQLITE_ROW) {
        const unsigned char* code = sqlite3_column_text(db->stMorse, 0);

        if (code) {
            // Copied rather than handed back directly: the column pointer dies
            // at the reset below, and the caller has no way to know that.
            snprintf(db->morseCode, sizeof(db->morseCode), "%s", (const char*)code);
            *out = db->morseCode;
            hit = true;
        }
    }

    sqlite3_reset(db->stMorse);

    return hit;
}

// ---------------------------------------------------------------------------
// Frequency parsing
// ---------------------------------------------------------------------------

// Copies a TEXT column into a fixed buffer, tolerating NULL.
static void copy_text(sqlite3_stmt* st, int col, char* dst, size_t cap) {
    const unsigned char* v = sqlite3_column_text(st, col);
 
    snprintf(dst, cap, "%s", v ? (const char*)v : "");
}
 
bool hammy_freq_parse(const char* text, int64_t* outHz) {
    if (!text || !outHz) { return false; }
 
    while (*text == ' ' || *text == '\t') { text++; }
 
    // Integer part.
    int64_t whole = 0;
    bool anyDigit = false;
 
    while (*text >= '0' && *text <= '9') {
        if (whole > INT64_MAX / 10 - 9) { return false; }   // absurd input
        whole = whole * 10 + (*text - '0');
        anyDigit = true;
        text++;
    }
 
    // Fractional part, accumulated as digits rather than a double. Six decimal
    // places of MHz is exactly 1 Hz, so anything beyond that is discarded.
    int64_t frac = 0;
    int fracDigits = 0;
 
    if (*text == '.' || *text == ',') {
        text++;
 
        while (*text >= '0' && *text <= '9') {
            if (fracDigits < 9) {
                frac = frac * 10 + (*text - '0');
                fracDigits++;
            }
            anyDigit = true;
            text++;
        }
    }
 
    if (!anyDigit) { return false; }
 
    while (*text == ' ' || *text == '\t') { text++; }
 
    // Unit. A bare number means MHz, which is what people type.
    int64_t mult = 1000000;     // Hz per unit
 
    if (*text) {
        char unit[8] = {0};
        size_t i = 0;
 
        while (text[i] && i + 1 < sizeof(unit) && text[i] != ' ') {
            char c = text[i];
            unit[i] = (c >= 'A' && c <= 'Z') ? (char)(c - 'A' + 'a') : c;
            i++;
        }
 
        if (!strcmp(unit, "hz"))                                { mult = 1; }
        else if (!strcmp(unit, "khz") || !strcmp(unit, "k"))    { mult = 1000; }
        else if (!strcmp(unit, "mhz") || !strcmp(unit, "m"))    { mult = 1000000; }
        else if (!strcmp(unit, "ghz") || !strcmp(unit, "g"))    { mult = 1000000000; }
        else { return false; }
    }
 
    // Scale the fraction to the unit without ever touching a double.
    int64_t scale = 1;
    for (int i = 0; i < fracDigits; i++) {
        if (scale > INT64_MAX / 10) { return false; }
        scale *= 10;
    }
 
    if (whole > INT64_MAX / mult) { return false; }
 
    int64_t hz = whole * mult + (frac * mult) / scale;
 
    if (hz <= 0 || hz > 300000000000LL) { return false; }   // 1 Hz .. 300 GHz
 
    *outHz = hz;
 
    return true;
}

// ---------------------------------------------------------------------------
// Frequency lookup
// ---------------------------------------------------------------------------

static void normalise_country(const char* in, char* out, size_t cap) {
    size_t j = 0;
 
    if (!in || !*in) {
        snprintf(out, cap, "US");   // default
        return;
    }
 
    for (size_t i = 0; in[i] && j + 1 < cap; i++) {
        char c = in[i];
 
        if (c >= 'a' && c <= 'z') { c = (char)(c - 'a' + 'A'); }
        if (c >= 'A' && c <= 'Z') { out[j++] = c; }
    }
 
    out[j] = '\0';
 
    if (!out[0]) { snprintf(out, cap, "US"); }
}
 
static bool step_bool(sqlite3_stmt* st) {
    bool got = (sqlite3_step(st) == SQLITE_ROW);
    sqlite3_reset(st);
 
    return got;
}
 
bool hammy_refdb_freq(hammy_refdb_t* db, int64_t freqHz, const char* country,
                      hammy_freq_t* out) {
    if (!db || !out || freqHz <= 0) { return false; }

    sqlite3_stmt* const needed[] = {
        db->stFreqMain, db->stFreqIaru, db->stFreqNearest,
        db->stFreqSegEdge, db->stCountryKnown
    };
    if (!stmts_ready("freq", needed, 5)) { return false; }
 
    memset(out, 0, sizeof(*out));
    out->freqHz = freqHz;
    normalise_country(country, out->country, sizeof(out->country));
 
    // Does the bundle know this country at all? Only US privileges are seeded so
    // far, so this is the common path and the message matters.
    sqlite3_reset(db->stCountryKnown);
    sqlite3_clear_bindings(db->stCountryKnown);
    sqlite3_bind_text(db->stCountryKnown, 1, out->country, -1, SQLITE_TRANSIENT);
    out->countryKnown = step_bool(db->stCountryKnown);
 
    // Band and privileges.
    sqlite3_stmt* st = db->stFreqMain;
    sqlite3_reset(st);
    sqlite3_clear_bindings(st);
    sqlite3_bind_int64(st, 1, freqHz);
    sqlite3_bind_text(st, 2, out->country, -1, SQLITE_TRANSIENT);
 
    while (sqlite3_step(st) == SQLITE_ROW) {
        if (!out->inBand) {
            out->inBand = true;
            copy_text(st, 0, out->band, sizeof(out->band));
            out->bandLowHz = sqlite3_column_int64(st, 1);
            out->bandHighHz = sqlite3_column_int64(st, 2);
            out->atBandEdge = (freqHz == out->bandLowHz ||
                                 freqHz == out->bandHighHz);
        }
 
        // A NULL class means the country has no licence classes at all; the row
        // still carried the band, which is why it is read above first.
        if (sqlite3_column_type(st, 3) == SQLITE_NULL) { continue; }
        if (out->nPrivs >= HAMMY_FREQ_PRIVS_MAX) { continue; }
 
        hammy_freq_priv_t* p = &out->privs[out->nPrivs++];
 
        copy_text(st, 3, p->code, sizeof(p->code));
        copy_text(st, 4, p->name, sizeof(p->name));
        p->rank = sqlite3_column_int(st, 5);
 
        p->permitted = (sqlite3_column_type(st, 6) != SQLITE_NULL);
 
        if (p->permitted) {
            copy_text(st, 6, p->modes, sizeof(p->modes));
            p->segLowHz = sqlite3_column_int64(st, 7);
            p->segHighHz = sqlite3_column_int64(st, 8);
            p->maxPowerW = sqlite3_column_int(st, 9);   // 0 when NULL
            copy_text(st, 10, p->notes, sizeof(p->notes));
        }
    }
 
    sqlite3_reset(st);
 
    // Not in any band: report the nearest one so the user can see how far off
    // they are. Usually a typo - 15.000 instead of 14.150.
    if (!out->inBand) {
        st = db->stFreqNearest;
        sqlite3_reset(st);
        sqlite3_clear_bindings(st);
        sqlite3_bind_int64(st, 1, freqHz);
 
        if (sqlite3_step(st) == SQLITE_ROW) {
            copy_text(st, 0, out->nearestBand, sizeof(out->nearestBand));
            out->nearestLowHz = sqlite3_column_int64(st, 1);
            out->nearestHighHz = sqlite3_column_int64(st, 2);
            out->nearestDistanceHz = sqlite3_column_int64(st, 3);
        }
 
        sqlite3_reset(st);
 
        return true;
    }
 
    // IARU regional allocations. Independent of country, so worth showing even
    // when the privilege table is empty.
    st = db->stFreqIaru;
    sqlite3_reset(st);
    sqlite3_clear_bindings(st);
    sqlite3_bind_int64(st, 1, freqHz);
 
    while (sqlite3_step(st) == SQLITE_ROW && out->nIaru < HAMMY_FREQ_IARU_MAX) {
        hammy_freq_iaru_t* r = &out->iaru[out->nIaru++];
 
        r->region = sqlite3_column_int(st, 0);
        r->lowHz = sqlite3_column_int64(st, 1);
        r->highHz = sqlite3_column_int64(st, 2);
        copy_text(st, 3, r->modes, sizeof(r->modes));
    }
 
    sqlite3_reset(st);
 
    // Sitting exactly on a segment boundary is worth flagging: a signal of any
    // width centred there straddles both sides.
    st = db->stFreqSegEdge;
    sqlite3_reset(st);
    sqlite3_clear_bindings(st);
    sqlite3_bind_int64(st, 1, freqHz);
    sqlite3_bind_text(st, 2, out->country, -1, SQLITE_TRANSIENT);
    out->atSegmentEdge = step_bool(st);
 
    return true;
}
 
size_t hammy_refdb_countries(hammy_refdb_t* db,
                             char out[][HAMMY_COUNTRY_MAX], size_t cap) {
    if (!db || !out || cap == 0 || !db->stCountryList) { return 0; }
 
    size_t n = 0;
 
    sqlite3_reset(db->stCountryList);
 
    while (n < cap && sqlite3_step(db->stCountryList) == SQLITE_ROW) {
        copy_text(db->stCountryList, 0, out[n++], HAMMY_COUNTRY_MAX);
    }
 
    sqlite3_reset(db->stCountryList);
 
    return n;
}
