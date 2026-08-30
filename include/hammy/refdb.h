#ifndef HAMMY_REFDB_H
#define HAMMY_REFDB_H

#include <stdbool.h>
#include <stddef.h>
#include <sqlite3.h>

#include <hammy/types.h>

// Read-only handle to the reference bundle. Owned by exactly one thread.
// Theading rules: Do NOT share a hammy_refdb_t between threads. Instead, a worker should
// open it's own in hammy_worker_start(), and the gateway should open one for instant
// commands. The bundle is read-only, so no writers for sync. Seperate sqlite3 connections
// never contend.

#define HAMMY_CALLSIGN_MAX 32
#define HAMMY_ENTITY_NAME_MAX 64
// Longest code in the morse table is '$' ('...-..-'), seven characters.
#define HAMMY_MORSE_MAX 16

struct hammy_refdb_t {
    sqlite3* handle;
    sqlite3_stmt* stExact;
    sqlite3_stmt* stPrefix;
    sqlite3_stmt* stMorse;
    char morseCode[HAMMY_MORSE_MAX]; // Scratch for the last hammy_refdb_get_morse() hit
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

// Opens the bundle read-only and prepares the hot statements.
// Returns NULL and logs on failure.
hammy_refdb_t* hammy_refdb_open(const char* path);
 
// Finalises statements and closes the connection. NULLs the passing reference.
bool hammy_refdb_close(hammy_refdb_t** db);

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
 
// Bundle version string from ref_meta, or NULL. Owned by the refdb.
const char* hammy_refdb_version(hammy_refdb_t* db);

#endif
