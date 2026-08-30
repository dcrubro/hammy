#include <concord/log.h>
#include <stdlib.h>
#include <string.h>

#include <hammy/refdb.h>

// Whole-callsign rules (cty.dat's "=CALL" entries) must match the entire string.
static const char* SQL_EXACT =
    "SELECT e.id, e.name, e.continent,"
    "       COALESCE(p.cq_zone, e.cq_zone), COALESCE(p.itu_zone, e.itu_zone),"
    "       e.latitude, e.longitude, e.utc_offset, p.prefix"
    "  FROM dxcc_prefixes p JOIN dxcc_entities e ON e.id = p.entity_id"
    " WHERE p.prefix = ?1 AND p.exact = 1"
    " LIMIT 1";
 
// One candidate at a time, called longest-first by the caller.
static const char* SQL_PREFIX =
    "SELECT e.id, e.name, e.continent,"
    "       COALESCE(p.cq_zone, e.cq_zone), COALESCE(p.itu_zone, e.itu_zone),"
    "       e.latitude, e.longitude, e.utc_offset, p.prefix"
    "  FROM dxcc_prefixes p JOIN dxcc_entities e ON e.id = p.entity_id"
    " WHERE p.prefix = ?1 AND p.exact = 0"
    " LIMIT 1";
 
static const char* SQL_VERSION =
    "SELECT value FROM ref_meta WHERE key = 'bundle_version'";

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

static bool prepare(sqlite3* h, const char* sql, sqlite3_stmt** out) {
    if (sqlite3_prepare_v2(h, sql, -1, out, NULL) != SQLITE_OK) {
        log_error("[refdb] prepare failed: %s", sqlite3_errmsg(h));
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

    if (!prepare(db->handle, SQL_EXACT, &db->stExact)) { goto fail; }
    if (!prepare(db->handle, SQL_PREFIX, &db->stPrefix)) { goto fail; }

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
    if (d->stExact) { sqlite3_finalize(d->stExact); }
    if (d->stPrefix) { sqlite3_finalize(d->stPrefix); }
    
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

