#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include <hammy/command.h>
#include <hammy/commands.h>
#include <hammy/job.h>
#include <hammy/refdb.h>
#include <hammy/utils.h>

// The reply goes out as an embed description, which Discord caps at 4096
// characters, so the two halves get separate budgets that still leave room for
// the labels between them. Capping at all is what keeps an unbounded,
// user-controlled VLA off the stack: a command option runs to 6000 characters,
// and every one of them can expand to a whole word.
#define HAMMY_PHONETIC_CODE_MAX 1536
#define HAMMY_PHONETIC_PRONUNCIATION_MAX 1536
#define HAMMY_PHONETIC_TRUNCATED " ... (truncated)"

// Appends one token, space-separated from whatever is already in the buffer and
// optionally preceded by a word-gap slash. All or nothing: returns false and
// leaves the buffer untouched when the whole thing would not fit, so the caller
// can stop without a half-written word on the end.
//
// len counts bytes excluding the terminator, and the buffer stays terminated
// throughout - which is what the strcat-onto-uninitialised-stack version this
// replaces got wrong: strcat needs a terminated destination to start from, and
// an uninitialised one made the reply random bytes that Discord rejected as
// invalid JSON.
static bool phonetic_append(char* buf, size_t cap, size_t* len, bool gap, const char* token) {
    size_t n = strlen(token);
    size_t need = (*len > 0 ? 1u : 0u) + (gap ? 2u : 0u) + n;

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

static bool phonetic_is_gap(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_phonetic(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    // Get the text argument from the job
    const char* text = hammy_job_get_arg(job, "text");
    if (!text) {
        hammy_job_respond(job, client, "Text Missing!", "No Text provided for Phonetic conversion.", true);
        return;
    }

    if (strlen(text) >= 128) {
        hammy_job_respond(job, client, "Text Too Long!", "Text provided is too long! Max. 128 characters.", true);
        return;
    }

    bool showPronunciation = strlen(text) < 12;

    char phonetic[HAMMY_PHONETIC_CODE_MAX + sizeof(HAMMY_PHONETIC_TRUNCATED)];
    char pronunciation[HAMMY_PHONETIC_PRONUNCIATION_MAX + sizeof(HAMMY_PHONETIC_TRUNCATED)];

    phonetic[0] = '\0';
    pronunciation[0] = '\0';

    // Room held back so the truncation note always fits.
    const size_t phoneticCap = sizeof(phonetic) - (sizeof(HAMMY_PHONETIC_TRUNCATED) - 1);
    const size_t pronunciationCap = sizeof(pronunciation) - (sizeof(HAMMY_PHONETIC_TRUNCATED) - 1);

    size_t phoneticLen = 0;
    size_t pronunciationLen = 0;
    bool pendingGap = false;
    bool truncated = false;

    for (const char* p = text; *p; p++) {
        // The phonetic table has no row for whitespace, and rendering it as an
        // unknown character would lose the word boundaries. Held rather than
        // emitted on the spot so leading, trailing and repeated spaces do not
        // stack up slashes.
        if (phonetic_is_gap(*p)) {
            pendingGap = (phoneticLen > 0);
            continue;
        }

        const char* code = NULL;
        const char* codePronunciation = NULL;
        if (!hammy_refdb_get_phonetic(refdb, *p, &code, &codePronunciation)) {
            // Both halves get a placeholder: leaving the pronunciation at NULL
            // would hand strlen() a null pointer on the next append.
            code = "?"; // Handle unknown characters
            codePronunciation = "?";
        }

        // The two halves are read side by side, so they have to stay on the same
        // character. A word that fits in one buffer but not the other is rolled
        // back out of the first rather than left to skew the columns.
        size_t phoneticMark = phoneticLen;

        if (!phonetic_append(phonetic, phoneticCap, &phoneticLen, pendingGap, code) ||
            !phonetic_append(pronunciation, pronunciationCap, &pronunciationLen, pendingGap, codePronunciation)) {
            phoneticLen = phoneticMark;
            phonetic[phoneticLen] = '\0';
            truncated = true;
            break;
        }

        pendingGap = false;
    }

    // All whitespace, or an empty string: Discord refuses an empty body, so
    // there is nothing to send back.
    if (phoneticLen == 0) {
        hammy_job_respond(job, client, "Error", "Nothing to convert.", true);
        return;
    }

    if (truncated) {
        memcpy(phonetic + phoneticLen, HAMMY_PHONETIC_TRUNCATED, sizeof(HAMMY_PHONETIC_TRUNCATED));
        memcpy(pronunciation + pronunciationLen, HAMMY_PHONETIC_TRUNCATED, sizeof(HAMMY_PHONETIC_TRUNCATED));
    }

    hammy_to_uppercase(text);

    // Reply with the phonetic words and how each of them is spoken.
    char body[sizeof(phonetic) + sizeof(pronunciation) + 48];
    if (showPronunciation) {
        snprintf(body, sizeof(body), "Text: `%s`\nPhonetics: `%s`\nPronunciation: `%s`", text, phonetic, pronunciation);
    } else {
        snprintf(body, sizeof(body), "Text: `(truncated)`\nPhonetics: `%s`", phonetic);
    }

    hammy_job_respond(job, client, "Text to Phonetics Conversion", body, false);
}
