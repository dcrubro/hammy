#ifndef HAMMY_REFDB_H
#define HAMMY_REFDB_H

#include <stdbool.h>
#include <stddef.h>
#include <sqlite3.h>
#include <stdint.h>

#include <hammy/types.h>

// Read-only handle to the reference bundle. Owned by exactly one thread.
// Theading rules: Do NOT share a hammy_refdb_t between threads. Instead, a worker should
// open it's own in hammy_worker_start(), and the gateway should open one for instant
// commands. The bundle is read-only, so no writers for sync. Seperate sqlite3 connections
// never contend.

#define HAMMY_CALLSIGN_MAX 32
#define HAMMY_ENTITY_NAME_MAX 64
#define HAMMY_COUNTRY_MAX 4

// Longest code in the morse table is '$' ('...-..-'), seven characters.
#define HAMMY_MORSE_MAX 16

// Longest Phonetic code. Fuck it, 32 characters
#define HAMMY_PHONETIC_MAX 32

// The current longest string in the qcodes table is 42; 128 is pretty generous. TODO: Change this if the qcodes table ever changes
#define HAMMY_QCODE_MAX 128

// A country has at most a handful of licence classes, each with at most a
// couple of segments covering one exact frequency. 24 is generous.
#define HAMMY_FREQ_PRIVS_MAX 24
#define HAMMY_FREQ_IARU_MAX 8
#define HAMMY_FREQ_COUNTRIES_MAX 64

struct hammy_refdb_t {
    sqlite3* handle;

    sqlite3_stmt* stExact;
    sqlite3_stmt* stPrefix;
    sqlite3_stmt* stMorse;
    sqlite3_stmt* stQCode;
    sqlite3_stmt* stPhonetic;
    sqlite3_stmt* stFreqMain;
    sqlite3_stmt* stFreqIaru;
    sqlite3_stmt* stFreqNearest;
    sqlite3_stmt* stFreqSegEdge;
    sqlite3_stmt* stCountryKnown;
    sqlite3_stmt* stCountryList;

    char morseCode[HAMMY_MORSE_MAX]; // Scratch for the last hammy_refdb_get_morse() hit

    char phoneticCode[HAMMY_PHONETIC_MAX];
    char phoneticCodePronunciation[HAMMY_PHONETIC_MAX];

    char qcodeQuestion[HAMMY_QCODE_MAX]; // Scratch for the last hammy_refdb_get_qcode() hit
    char qcodeAnswer[HAMMY_QCODE_MAX]; // Scratch for the last hammy_refdb_get_qcode() hit

    char version[64];
};

struct hammy_dxcc_t {
    int entityId; // ADIF DXCC entity code
    char name[HAMMY_ENTITY_NAME_MAX];
    char continent[4];
    int cqZone; // Override applied if present
    int ituZone;
    double latitude;  // North-positive
    double longitude; // East-positive
    double utcOffset; // UTC + utcOffset = local
    char matchedPrefix[HAMMY_CALLSIGN_MAX];
    bool exact;
};
 
// ---------------------------------------------------------------------------
// Frequency lookup
// ---------------------------------------------------------------------------
struct hammy_freq_priv_t {
    char code[8];                   // 'E', 'G', 'T'
    char name[48];                  // 'Amateur Extra'
    int rank;
    bool permitted;                 // false = this class may NOT transmit here
    char modes[64];                 // 'CW,DATA' - empty when !permitted
    int64_t segLowHz;
    int64_t segHighHz;
    int maxPowerW;                  // 0 = national default, no specific limit
    char notes[160];
};
 
struct hammy_freq_iaru_t {
    int region;                     // 1, 2 or 3
    int64_t lowHz;
    int64_t highHz;
    char modes[32];
};
 
struct hammy_freq_t {
    int64_t freqHz;
 
    bool inBand;
    char band[16];                  // '20m'
    int64_t bandLowHz;
    int64_t bandHighHz;
 
    // The frequency sits exactly on a band or segment boundary. Worth saying
    // out loud: a signal of any width centred there straddles both sides.
    bool atBandEdge;
    bool atSegmentEdge;
 
    // False when the bundle carries no licence data for this country at all.
    // The band and IARU results are still valid; only the privilege table is
    // missing. Say so rather than showing an empty table.
    bool countryKnown;
    char country[HAMMY_COUNTRY_MAX];
 
    hammy_freq_priv_t privs[HAMMY_FREQ_PRIVS_MAX];
    size_t nPrivs;
 
    hammy_freq_iaru_t iaru[HAMMY_FREQ_IARU_MAX];
    size_t nIaru;
 
    // Only meaningful when !in_band.
    char nearestBand[16];
    int64_t nearestLowHz;
    int64_t nearestHighHz;
    int64_t nearestDistanceHz;
};

// ---------------------------------------------------------------------------
// Lifecycle
// ---------------------------------------------------------------------------

// Opens the bundle read-only and prepares the hot statements.
// Returns NULL and logs on failure.
hammy_refdb_t* hammy_refdb_open(const char* path);
 
// Finalises statements and closes the connection. NULLs the passing reference.
bool hammy_refdb_close(hammy_refdb_t** db);

// Bundle version string from ref_meta, or NULL. Owned by the refdb.
const char* hammy_refdb_version(hammy_refdb_t* db);

// ---------------------------------------------------------------------------
// Queries
// ---------------------------------------------------------------------------

// Resolves a callsign to a DXCC entity.
//
// Uses candidate-prefix equality seeks rather than "? GLOB prefix || '*'". The
// GLOB form puts the indexed column on the wrong side of the comparison, so
// SQLite scans all 7000 prefix rows; generating the candidates and seeking by
// equality is roughly 40x faster on the current bundle.
//
// Returns false if nothing matched.
bool hammy_refdb_dxcc(hammy_refdb_t* db, const char* callsign, hammy_dxcc_t* out);

// Looks up a character in the Morse table. Case-insensitive; non-ASCII bytes
// never match. Returns false if not found, leaving *out untouched.
//
// On a hit *out points at storage owned by the refdb and is only valid until
// the NEXT call on the same handle - copy it if it has to outlive that.
bool hammy_refdb_get_morse(hammy_refdb_t* db, char c, const char** out);

// Looks up a character in the Phonetic table. Case-insensitive; non-ASCII bytes
// never match. Returns false if not found, leaving *out untouched.
//
// On a hit *out points at storage owned by the refdb and is only valid until
// the NEXT call on the same handle - copy it if it has to outlive that.
bool hammy_refdb_get_phonetic(hammy_refdb_t* db, char c, const char** out, const char** outPronunciation);

// Looks up a QSO code in the qcodes table. Case-insensitive; non-ASCII bytes
// never match. Returns false if not found, leaving *out untouched.
//
// On a hit *out points at the storage owned by refdb and is only valid until
// the NEXT call on the same handle - copy it if it has to outlive that.
bool hammy_refdb_get_qcode(hammy_refdb_t* db, const char* code, const char** outQuestion, const char** outAnswer);

// What band is freq_hz in, and who may transmit there.
//
// country is an ISO 3166-1 alpha-2 code; NULL or empty means "US". Always
// returns true unless the arguments are bad: "not in a band" and "no data for
// that country" are results, not failures. Check out->in_band and
// out->country_known.
bool hammy_refdb_freq(hammy_refdb_t* db, int64_t freqHz, const char* country,
                      hammy_freq_t* out);
 
// Which countries have licence data, for the "no data for XX yet" message.
// Writes up to cap codes and returns how many were written.
size_t hammy_refdb_countries(hammy_refdb_t* db,
                             char out[][HAMMY_COUNTRY_MAX], size_t cap);

// ---------------------------------------------------------------------------
// Input parsing
// ---------------------------------------------------------------------------
 
// Parses a user-supplied frequency into integer Hz. Accepts "14.150",
// "14150 kHz", "146.52 MHz", "1.2 GHz", "14150000 Hz". A bare number with no
// unit is read as MHz, which is what people type.
//
// Deliberately avoids floating point: "14.150" is converted digit by digit to
// 14150000 exactly. Going via double gives 14150000.000000002, which compares
// wrong against an integer column at exactly a band edge - the one case where
// being right matters most.
//
// Returns false on unparseable input or a value outside 1 Hz .. 300 GHz.
bool hammy_freq_parse(const char* text, int64_t* outHz);


#endif
