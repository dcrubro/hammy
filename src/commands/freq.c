#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include <hammy/command.h>
#include <hammy/commands.h>
#include <hammy/job.h>
#include <hammy/refdb.h>

#define HAMMY_FREQ_BODY_MAX 3600

// Small append-only string builder. Every write is bounds-checked, so a country
// with thirty licence classes overflows into "truncated" rather than the stack.
typedef struct {
    char* buf;
    size_t cap;
    size_t len;
    bool overflow;
} hammy_sb_t;

static void sb_addf(hammy_sb_t* sb, const char* fmt, ...) {
    if (sb->overflow || sb->len + 1 >= sb->cap) {
        sb->overflow = true;
        return;
    }
 
    va_list ap;
    va_start(ap, fmt);
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wformat-nonliteral"
    int n = vsnprintf(sb->buf + sb->len, sb->cap - sb->len, fmt, ap);
    #pragma clang diagnostic pop
    va_end(ap);
 
    if (n < 0) {
        sb->overflow = true;
        return;
    }
 
    if ((size_t)n >= sb->cap - sb->len) {
        sb->len = sb->cap - 1;
        sb->overflow = true;
        return;
    }
 
    sb->len += (size_t)n;
}

// Hz -> MHz with three decimals, which is the resolution every band edge in the
// bundle actually uses. Integer maths so no rounding surprises at an edge.
static void fmt_mhz(int64_t hz, char* out, size_t cap) {
    int64_t whole = hz / 1000000;
    int64_t frac = (hz % 1000000) / 1000;
 
    snprintf(out, cap, "%" PRId64 ".%03" PRId64, whole, frac);
}
 
// 'CW,DATA' reads better as 'CW, DATA' in an embed.
static void fmt_modes(const char* modes, char* out, size_t cap) {
    size_t j = 0;
 
    for (size_t i = 0; modes[i] && j + 2 < cap; i++) {
        out[j++] = modes[i];
 
        if (modes[i] == ',' && j + 1 < cap) { out[j++] = ' '; }
    }
 
    out[j] = '\0';
}

// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_freq(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    if (!refdb) {
        hammy_job_respond(job, client, "Error", "Reference data is unavailable. Please try again later.", true);
        return;
    }
 
    const char* arg = hammy_job_get_arg(job, "frequency");
    if (!arg || !*arg) {
        hammy_job_respond(job, client, "Error", "No frequency provided for lookup.", true);
        return;
    }
 
    // Parses "14.150", "14150 kHz", "146.52 MHz". Integer maths throughout: a
    // bare (int64_t)cast of a float truncates BEFORE the multiply and turns
    // 14.150 into 14.000, which silently reports the wrong segment.
    int64_t freqHz = 0;
    if (!hammy_freq_parse(arg, &freqHz)) {
        hammy_job_respond(job, client, "Error", "I could not read that frequency. Try something like `14.150`, `7025 kHz` or `146.52 MHz`.", true);
        return;
    }
 
    const char* cc = hammy_job_get_arg(job, "country");   // NULL -> refdb uses US
 
    hammy_freq_t r;
    if (!hammy_refdb_freq(refdb, freqHz, cc, &r)) {
        hammy_job_respond(job, client, "Error", "Something went wrong looking that up.", true);
        return;
    }

    char freqStr[32];
    fmt_mhz(r.freqHz, freqStr, sizeof(freqStr));

    char body[HAMMY_FREQ_BODY_MAX];
    hammy_sb_t sb = { .buf = body, .cap = sizeof(body), .len = 0, .overflow = false };
    body[0] = '\0';

    // Not a valid ham band
    if (!r.inBand) {
        char lo[32], hi[32], dist[32];
        fmt_mhz(r.nearestLowHz, lo, sizeof(lo));
        fmt_mhz(r.nearestHighHz, hi, sizeof(hi));
        fmt_mhz(r.nearestDistanceHz, dist, sizeof(dist));

        sb_addf(&sb, "**%s MHz** is not in a valid amateur band.\n\n", freqStr);
        sb_addf(&sb, "Nearest is **%s** (%s - %s MHz), %s MHz away.", r.nearestBand, lo, hi, dist);

        hammy_job_respond(job, client, "Not an Amateur Band!", body, false);
        return;
    }

    char bandLo[32], bandHi[32];
    fmt_mhz(r.bandLowHz, bandLo, sizeof(bandLo));
    fmt_mhz(r.bandHighHz, bandHi, sizeof(bandHi));

    char title[128];
    snprintf(title, sizeof(title), "Band **%s** (%s - %s MHz)\n", r.band, bandLo, bandHi);

    // Privileges
    if (!r.countryKnown) {
        // The common case - only US data is seeded so far. Say what is missing
        // and what does exist, rather than showing an empty table.
        char codes[HAMMY_FREQ_COUNTRIES_MAX][HAMMY_COUNTRY_MAX];
        size_t n = hammy_refdb_countries(refdb, codes, HAMMY_FREQ_COUNTRIES_MAX);
 
        sb_addf(&sb, "\nNo licence data for **%s** in this bundle yet.\n", r.country);
 
        if (n) {
            sb_addf(&sb, "Currently available: ");
            for (size_t i = 0; i < n; i++) {
                sb_addf(&sb, "%s`%s`", i ? ", " : "", codes[i]);
            }
            sb_addf(&sb, "\n");
        }
 
        sb_addf(&sb, "Band plans are contributed by operators - if you know your regulator's allocations, please help fill this in.\n");
    } else if (r.nPrivs == 0) {
        sb_addf(&sb, "\nNo license classes are recorded for **%s**.\n", r.country);
    } else {
        sb_addf(&sb, "\n**Privileges in %s**\n", r.country);
 
        for (size_t i = 0; i < r.nPrivs; i++) {
            const hammy_freq_priv_t* p = &r.privs[i];
 
            if (!p->permitted) {
                sb_addf(&sb, "`%-14s` not permitted here\n", p->name);
                continue;
            }
 
            char lo[32], hi[32], modes[80];
            fmt_mhz(p->segLowHz, lo, sizeof(lo));
            fmt_mhz(p->segHighHz, hi, sizeof(hi));
            fmt_modes(p->modes, modes, sizeof(modes));
 
            sb_addf(&sb, "`%-14s` %s  (%s - %s", p->name, modes, lo, hi);
 
            if (p->maxPowerW > 0) {
                sb_addf(&sb, ", max %d W", p->maxPowerW);
            }
 
            sb_addf(&sb, ")\n");
 
            if (p->notes[0]) {
                sb_addf(&sb, "   *%s*\n", p->notes);
            }
        }
    }

    // IARU
    if (r.nIaru) {
        sb_addf(&sb, "\n**IARU Allocation**\n");

        for (size_t i = 0; i < r.nIaru; i++) {
            char lo[32], hi[32];
            fmt_mhz(r.iaru[i].lowHz, lo, sizeof(lo));
            fmt_mhz(r.iaru[i].highHz, hi, sizeof(hi));

            sb_addf(&sb, "Region %d: %s - %s MHz\n", r.iaru[i].region, lo, hi);
        }
    }

    // Boundary warnings
    if (r.atBandEdge) {
        sb_addf(&sb, "\n> This is exactly the band edge. A signal of any width centerd here extends outside the band.\n");
    } else if (r.atSegmentEdge) {
        sb_addf(&sb, "\n> This is exactly a segment boundary, so a signal centerd here straddles both sides.\n");
    }
 
    if (sb.overflow) {
        snprintf(body + sizeof(body) - 20, 20, "\n... truncated");
    }
 
    hammy_job_respond(job, client, title, body, false);
}
