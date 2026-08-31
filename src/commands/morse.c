#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/refdb.h>

#include <dlibc/vector.h>

// The reply goes out as an embed description, which Discord caps at 4096
// characters, so the two halves get separate budgets that still leave room for
// the labels between them. Capping at all is what keeps an unbounded,
// user-controlled VLA off the stack: a command option runs to 6000 characters,
// and every one of them can expand to eight.
#define HAMMY_MORSE_ECHO_MAX 512
#define HAMMY_MORSE_CODE_MAX 3072
#define HAMMY_MORSE_TRUNCATED " ... (truncated)"

// Appends one token, space-separated from whatever is already in the buffer and
// optionally preceded by a word-gap slash. All or nothing: returns false and
// leaves the buffer untouched when the whole thing would not fit, so the caller
// can stop without a half-written character on the end.
//
// len counts bytes excluding the terminator, and the buffer stays terminated
// throughout - which is what the strcat-onto-uninitialised-stack version this
// replaces got wrong: strcat needs a terminated destination to start from, and
// an uninitialised one made the reply random bytes that Discord rejected as
// invalid JSON.
static bool morse_append(char* buf, size_t cap, size_t* len, bool gap, const char* token) {
    size_t n = strlen(token);
    size_t need = (*len > 0 ? 1 : 0) + (gap ? 2 : 0) + n;

    if (*len + need + 1 > cap) { return false; }

    if (*len > 0) { buf[(*len)++] = ' '; }

    if (gap) {
        buf[(*len)++] = '/';
        buf[(*len)++] = ' ';
    }

    memcpy(buf + *len, token, n);
    *len += n;
    buf[*len] = '\0';

    return true;
}

static bool morse_is_gap(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// How many bytes of s can be kept without exceeding max OR splitting a UTF-8
// sequence. Half a sequence would make the JSON body invalid and cost the whole
// reply, so the cut walks back to the nearest lead byte.
//
// Only the echoed input needs this - the generated code is all ASCII.
static size_t morse_utf8_trim(const char* s, size_t max) {
    size_t n = strlen(s);
    if (n <= max) { return n; }

    // Continuation bytes are 10xxxxxx. Dropping back past them lands either on
    // ASCII or on the lead byte of the sequence being cut, and that lead byte
    // is then excluded too, since the kept range is [0, n).
    n = max;
    while (n > 0 && ((unsigned char)s[n] & 0xC0) == 0x80) { n--; }

    return n;
}

// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_morse(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    // Get the text argument from the job
    const char* text = hammy_job_get_arg(job, "text");
    if (!text) {
        hammy_job_respond(job, client, "Error", "No text provided for Morse code conversion.", true);
        return;
    }

    // Echoed back trimmed rather than whole: sizing a buffer from the option
    // would put an unbounded, user-controlled allocation on the stack.
    char echo[HAMMY_MORSE_ECHO_MAX + sizeof(HAMMY_MORSE_TRUNCATED)];
    size_t echoLen = morse_utf8_trim(text, HAMMY_MORSE_ECHO_MAX);

    memcpy(echo, text, echoLen);
    echo[echoLen] = '\0';

    if (text[echoLen] != '\0') {
        memcpy(echo + echoLen, HAMMY_MORSE_TRUNCATED, sizeof(HAMMY_MORSE_TRUNCATED));
    }

    char morse[HAMMY_MORSE_CODE_MAX + sizeof(HAMMY_MORSE_TRUNCATED)];
    morse[0] = '\0';

    // Room held back so the truncation note always fits.
    const size_t cap = sizeof(morse) - (sizeof(HAMMY_MORSE_TRUNCATED) - 1);

    size_t len = 0;
    bool pendingGap = false;
    bool truncated = false;

    for (const char* p = text; *p; p++) {
        // The morse table has no row for whitespace, and rendering it as an
        // unknown character would lose the word boundaries. Held rather than
        // emitted on the spot so leading, trailing and repeated spaces do not
        // stack up slashes.
        if (morse_is_gap(*p)) {
            pendingGap = (len > 0);
            continue;
        }

        const char* code = NULL;
        if (!hammy_refdb_get_morse(refdb, *p, &code)) {
            code = "?"; // Handle unknown characters
        }

        if (!morse_append(morse, cap, &len, pendingGap, code)) {
            truncated = true;
            break;
        }

        pendingGap = false;
    }

    // All whitespace, or an empty string: Discord refuses an empty body, so
    // there is nothing to send back.
    if (len == 0) {
        hammy_job_respond(job, client, "Error", "Nothing to convert.", true);
        return;
    }

    if (truncated) {
        memcpy(morse + len, HAMMY_MORSE_TRUNCATED, sizeof(HAMMY_MORSE_TRUNCATED));
    }

    // Reply with the converted Morse code, alongside the text it came from.
    char body[sizeof(echo) + sizeof(morse) + 32];
    snprintf(body, sizeof(body), "Original text: `%s`\nMorse: `%s`", echo, morse);

    hammy_job_respond(job, client, "Morse Code Conversion", body, false);
}
