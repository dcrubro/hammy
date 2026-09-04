#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include <hammy/geo.h>

// M_PI is POSIX, not C99, so it is absent under -std=c99 without _GNU_SOURCE.
// Defining it here keeps the build strict and portable.
#define HAMMY_PI 3.14159265358979323846

// IUGG mean Earth radius. Any of the common radii agree to well within the
// error a 6-character grid square already carries.
#define HAMMY_EARTH_RADIUS_KM 6371.0088
#define HAMMY_EARTH_CIRCUM_KM (2.0 * HAMMY_PI * HAMMY_EARTH_RADIUS_KM)

static double deg_to_rad(double deg) { return deg * HAMMY_PI / 180.0; }
static double rad_to_deg(double rad) { return rad * 180.0 / HAMMY_PI; }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbad-function-cast" // suppresses the dumb floor() cast to int warning
bool hammy_grid_from_latlon(double lat, double lon, int precision, char* out, size_t cap) {
    if (!out || cap < 3) { return false; }
    if (lat < -90.0 || lat > 90.0 || lon < -180.0 || lon > 180.0) { return false; }
    if (precision != 2 && precision != 4 && precision != 6 && precision != 8) { return false; }
    if (cap < (size_t)precision + 1) { return false; }

    // Shift into the all-positive space the locator system is defined over.
    double lonA = lon + 180.0;
    double latA = lat + 90.0;

    // Clamp the poles and the antimeridian so floor() cannot walk off the end
    // of the field letters at exactly +90 / +180.
    if (lonA >= 360.0) { lonA = 359.999999; }
    if (latA >= 180.0) { latA = 179.999999; }

    int i = 0;

    int f1 = (int)floor(lonA / 20.0);
    int f2 = (int)floor(latA / 10.0);
    out[i++] = (char)('A' + f1);
    out[i++] = (char)('A' + f2);

    double remLon = lonA - f1 * 20.0;
    double remLat = latA - f2 * 10.0;

    if (precision >= 4) {
        int s1 = (int)floor(remLon / 2.0);
        int s2 = (int)floor(remLat / 1.0);
        out[i++] = (char)('0' + s1);
        out[i++] = (char)('0' + s2);

        remLon -= s1 * 2.0;
        remLat -= s2 * 1.0;
    }

    if (precision >= 6) {
        // A square is 2 deg of longitude by 1 deg of latitude, divided 24 ways.
        int ss1 = (int)floor(remLon / (2.0 / 24.0));
        int ss2 = (int)floor(remLat / (1.0 / 24.0));
        if (ss1 > 23) { ss1 = 23; }
        if (ss2 > 23) { ss2 = 23; }
        out[i++] = (char)('a' + ss1);
        out[i++] = (char)('a' + ss2);

        remLon -= ss1 * (2.0 / 24.0);
        remLat -= ss2 * (1.0 / 24.0);
    }

    if (precision >= 8) {
        int e1 = (int)floor(remLon / (2.0 / 240.0));
        int e2 = (int)floor(remLat / (1.0 / 240.0));
        if (e1 > 9) { e1 = 9; }
        if (e2 > 9) { e2 = 9; }
        out[i++] = (char)('0' + e1);
        out[i++] = (char)('0' + e2);
    }

    out[i] = '\0';

    return true;
}

bool hammy_grid_to_latlon(const char* grid, double* outLat, double* outLon) {
    if (!grid || !outLat || !outLon) { return false; }

    char g[HAMMY_GRID_MAX];
    size_t n = 0;

    for (size_t i = 0; grid[i]; i++) {
        if (isspace((unsigned char)grid[i])) { continue; }

        // Reject rather than truncate. Silently clipping "IO91wm12345" to
        // "IO91wm12" would hand back a plausible-looking position for input the
        // user clearly got wrong.
        if (n + 1 >= sizeof(g)) { return false; }

        g[n++] = grid[i];
    }
    g[n] = '\0';

    // Locators come in even-length pairs; 2, 4, 6 and 8 are the useful ones.
    if (n != 2 && n != 4 && n != 6 && n != 8) { return false; }

    int f1 = toupper((unsigned char)g[0]) - 'A';
    int f2 = toupper((unsigned char)g[1]) - 'A';
    if (f1 < 0 || f1 > 17 || f2 < 0 || f2 > 17) { return false; }

    double lon = f1 * 20.0;
    double lat = f2 * 10.0;
    double lonSize = 20.0;
    double latSize = 10.0;

    if (n >= 4) {
        if (!isdigit((unsigned char)g[2]) || !isdigit((unsigned char)g[3])) { return false; }
        lon += (g[2] - '0') * 2.0;
        lat += (g[3] - '0') * 1.0;
        lonSize = 2.0;
        latSize = 1.0;
    }

    if (n >= 6) {
        int s1 = tolower((unsigned char)g[4]) - 'a';
        int s2 = tolower((unsigned char)g[5]) - 'a';
        if (s1 < 0 || s1 > 23 || s2 < 0 || s2 > 23) { return false; }
        lon += s1 * (2.0 / 24.0);
        lat += s2 * (1.0 / 24.0);
        lonSize = 2.0 / 24.0;
        latSize = 1.0 / 24.0;
    }

    if (n >= 8) {
        if (!isdigit((unsigned char)g[6]) || !isdigit((unsigned char)g[7])) { return false; }
        lon += (g[6] - '0') * (2.0 / 240.0);
        lat += (g[7] - '0') * (1.0 / 240.0);
        lonSize = 2.0 / 240.0;
        latSize = 1.0 / 240.0;
    }

    // Report the CENTER of the square, not its south-west corner. Using the
    // corner biases every distance by up to half a square, which at 4-character
    // precision is about 60 km.
    *outLon = lon + lonSize / 2.0 - 180.0;
    *outLat = lat + latSize / 2.0 - 90.0;

    return true;
}

void hammy_great_circle(double lat1, double lon1, double lat2, double lon2,
                        double* outDistKm, double* outBearingDeg) {
    double p1 = deg_to_rad(lat1);
    double p2 = deg_to_rad(lat2);
    double dp = p2 - p1;
    double dl = deg_to_rad(lon2 - lon1);

    if (outDistKm) {
        // Haversine. The spherical law of cosines is shorter but loses precision
        // for short distances, which is exactly the "how far to the next town"
        // case people try first.
        double a = sin(dp / 2.0) * sin(dp / 2.0)
                 + cos(p1) * cos(p2) * sin(dl / 2.0) * sin(dl / 2.0);
        if (a > 1.0) { a = 1.0; }

        *outDistKm = 2.0 * HAMMY_EARTH_RADIUS_KM * asin(sqrt(a));
    }

    if (outBearingDeg) {
        double y = sin(dl) * cos(p2);
        double x = cos(p1) * sin(p2) - sin(p1) * cos(p2) * cos(dl);
        double b = rad_to_deg(atan2(y, x));

        *outBearingDeg = fmod(b + 360.0, 360.0);
    }
}

double hammy_long_path_km(double shortPathKm) {
    return HAMMY_EARTH_CIRCUM_KM - shortPathKm;
}

double hammy_reciprocal_bearing(double bearingDeg) {
    return fmod(bearingDeg + 180.0, 360.0);
}

const char* hammy_compass_point(double bearingDeg) {
    static const char* POINTS[16] = {
        "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
        "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"
    };

    double b = fmod(bearingDeg + 360.0, 360.0);
    int idx = (int)floor((b + 11.25) / 22.5) % 16;

    return POINTS[idx];
}

#pragma clang diagnostic pop
