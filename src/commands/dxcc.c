#include <concord/discord.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <hammy/command.h>
#include <hammy/commands.h>
#include <hammy/geo.h>
#include <hammy/job.h>
#include <hammy/refdb.h>
#include <hammy/utils.h>

#define HAMMY_DXCC_BODY_MAX 2048
#define HAMMY_DXCC_TITLE_MAX 128

// Formats a signed decimal degree as "38.90 N" / "77.04 W".
static void hammy_dxcc_fmt_coord(double value, bool isLatitude, char* out, size_t cap) {
    char hemi = isLatitude ? (value >= 0.0 ? 'N' : 'S')
                           : (value >= 0.0 ? 'E' : 'W');

    snprintf(out, cap, "%.2f %c", fabs(value), hemi);
}

// Formats a UTC offset as "UTC+9", "UTC-5", "UTC+5:30". cty.dat carries half
// hour offsets for a handful of entities, so the fractional case is real.
static void hammy_dxcc_fmt_offset(double offset, char* out, size_t cap) {
    int totalMinutes = (int)lround(offset * 60.0);
    char sign = totalMinutes < 0 ? '-' : '+';

    if (totalMinutes < 0) { totalMinutes = -totalMinutes; }

    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    if (minutes) {
        snprintf(out, cap, "UTC%c%d:%02d", sign, hours, minutes);
    } else {
        snprintf(out, cap, "UTC%c%d", sign, hours);
    }
}

// Wall-clock time at the entity. cty.dat gives STANDARD offsets with no notion
// of summer time, so this can be an hour out for part of the year. Said so in
// the output rather than quietly presenting it as exact.
static void hammy_dxcc_fmt_local_time(double offset, char* out, size_t cap) {
    time_t now = time(NULL);

    if (now == (time_t)-1) {
        snprintf(out, cap, "unknown");
        return;
    }

    time_t shifted = now + (time_t)lround(offset * 3600.0);
    struct tm tmBuf;

    // gmtime_r rather than gmtime: instant commands run on the gateway thread
    // and deferred ones on a worker, and gmtime's static buffer is shared.
    if (!gmtime_r(&shifted, &tmBuf)) {
        snprintf(out, cap, "unknown");
        return;
    }

    snprintf(out, cap, "%02d:%02d", tmBuf.tm_hour, tmBuf.tm_min);
}

// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_dxcc(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    if (!refdb) {
        hammy_job_respond(job, client, "Error", "Reference data is unavailable. Please try again later.", true);
        return;
    }

    const char* callsign = hammy_job_get_arg(job, "callsign");
    if (!callsign || !*callsign) {
        hammy_job_respond(job, client, "Error", "No callsign provided for lookup.", true);
        return;
    }

    hammy_dxcc_t entity;
    if (!hammy_refdb_dxcc(refdb, callsign, &entity)) {
        char body[HAMMY_DXCC_BODY_MAX];

        snprintf(body, sizeof(body),
                 "No DXCC entity matches `%s`.\n\n"
                 "Prefixes are matched longest-first, so this usually means a typo "
                 "or a prefix that has never been allocated.", callsign);

        hammy_job_respond(job, client, "Entity Not Found!", body, true);
        return;
    }

    char gridStr[HAMMY_GRID_MAX] = "unknown";
    bool haveEntityGrid = hammy_grid_from_latlon(entity.latitude, entity.longitude, 6,
                                                 gridStr, sizeof(gridStr));

    char latStr[24];
    char lonStr[24];
    hammy_dxcc_fmt_coord(entity.latitude, true, latStr, sizeof(latStr));
    hammy_dxcc_fmt_coord(entity.longitude, false, lonStr, sizeof(lonStr));

    char offsetStr[24];
    char timeStr[16];
    hammy_dxcc_fmt_offset(entity.utcOffset, offsetStr, sizeof(offsetStr));
    hammy_dxcc_fmt_local_time(entity.utcOffset, timeStr, sizeof(timeStr));

    char title[HAMMY_DXCC_TITLE_MAX];
    char upperCallsign[HAMMY_CALLSIGN_MAX];
    snprintf(upperCallsign, sizeof(upperCallsign), "%s", callsign);
    hammy_to_uppercase(upperCallsign);
    snprintf(title, sizeof(title), "%s - %s", upperCallsign, entity.name);

    char body[HAMMY_DXCC_BODY_MAX];
    int len = 0;

    len += snprintf(body + len, sizeof(body) - (size_t)len,
                    "Entity: `%s` (DXCC `%d`)\n"
                    "Continent: `%s`  CQ zone: `%d`  ITU zone: `%d`\n",
                    entity.name, entity.entityId, entity.continent,
                    entity.cqZone, entity.ituZone);

    if (haveEntityGrid) {
        len += snprintf(body + len, sizeof(body) - (size_t)len,
                        "Location: `%s` (%s, %s)\n", gridStr, latStr, lonStr);
    } else {
        len += snprintf(body + len, sizeof(body) - (size_t)len,
                        "Location: %s, %s\n", latStr, lonStr);
    }

    len += snprintf(body + len, sizeof(body) - (size_t)len,
                    "Local time: `%s` (`%s`, standard time)\n", timeStr, offsetStr);

    // Saying WHICH rule matched matters more than it looks. An exact hit means
    // cty.dat carries a whole-callsign override, and a short prefix hit on a
    // long callsign is a hint that the entity guess may be loose.
    if (entity.exact) {
        len += snprintf(body + len, sizeof(body) - (size_t)len,
                        "Matched: exact callsign rule `%s`\n", entity.matchedPrefix);
    } else {
        len += snprintf(body + len, sizeof(body) - (size_t)len,
                        "Matched: prefix `%s`\n", entity.matchedPrefix);
    }

    // Optional second argument: the asker's own locator, which turns this from
    // trivia into something you can point an antenna with.
    const char* fromGrid = hammy_job_get_arg(job, "grid");

    if (fromGrid && *fromGrid) {
        double fromLat = 0.0;
        double fromLon = 0.0;

        if (!hammy_grid_to_latlon(fromGrid, &fromLat, &fromLon)) {
            len += snprintf(body + len, sizeof(body) - (size_t)len,
                            "\nCould not read `%s` as a Maidenhead locator. "
                            "Try something like `JN76` or `JN76gb`.\n", fromGrid);
        } else {
            double distKm = 0.0;
            double bearing = 0.0;
            hammy_great_circle(fromLat, fromLon, entity.latitude, entity.longitude,
                               &distKm, &bearing);

            double longKm = hammy_long_path_km(distKm);
            double longBearing = hammy_reciprocal_bearing(bearing);

            char fromNorm[HAMMY_GRID_MAX];
            if (!hammy_grid_from_latlon(fromLat, fromLon, 6, fromNorm, sizeof(fromNorm))) {
                snprintf(fromNorm, sizeof(fromNorm), "%s", fromGrid);
            }

            len += snprintf(body + len, sizeof(body) - (size_t)len,
                            "\n**From %s**\n"
                            "Short path: `%.0f km` (`%.0f mi`) bearing `%.0f` (%s)\n"
                            "Long path: `%.0f km` bearing `%.0f` (%s)\n",
                            fromNorm,
                            distKm, distKm * 0.621371, bearing, hammy_compass_point(bearing),
                            longKm, longBearing, hammy_compass_point(longBearing));
        }
    }

    // The entity coordinates are a nominal center for the whole entity, not the
    // station's own position. For the US that is a point in Washington DC, so a
    // bearing to a California station will be well off. Worth admitting.
    len += snprintf(body + len, sizeof(body) - (size_t)len,
                    "\n-# Coordinates are the entity's nominal center, not the "
                    "station's actual location.");

    (void)len;

    hammy_job_respond(job, client, title, body, false);
}
