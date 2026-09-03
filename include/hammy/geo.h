#ifndef HAMMY_GEO_H
#define HAMMY_GEO_H

#include <stdbool.h>
#include <stddef.h>

// Maidenhead locators and great-circle maths. No dependencies beyond libm, no
// state, no database - safe to call from any thread.
//
// Lives in its own module rather than utils.h because /grid, /beacon and /sat
// will all want it, and mixing coordinate maths in with string helpers makes
// both harder to find.

// 8 characters plus NUL. Longer locators exist in theory; nothing uses them.
#define HAMMY_GRID_MAX 9

// Writes a Maidenhead locator for the given coordinates. precision must be
// 2 (field), 4 (square), 6 (subsquare) or 8 (extended square); 6 is what people
// quote. Returns false on out-of-range coordinates, bad precision, or too small
// a buffer.
bool hammy_grid_from_latlon(double lat, double lon, int precision, char* out, size_t cap);

// Parses a 2, 4, 6 or 8 character locator. Case-insensitive, ignores embedded
// whitespace, rejects anything longer rather than truncating it.
//
// Returns the CENTER of the square, not its south-west corner: using the corner
// biases every distance by up to half a square, which at 4-character precision
// is about 60 km.
bool hammy_grid_to_latlon(const char* grid, double* outLat, double* outLon);

// Haversine distance in km and initial bearing in degrees true. Either output
// pointer may be NULL.
void hammy_great_circle(double lat1, double lon1, double lat2, double lon2,
                        double* outDistKm, double* outBearingDeg);

// The other way round the planet.
double hammy_long_path_km(double shortPathKm);
double hammy_reciprocal_bearing(double bearingDeg);

// 16-point compass abbreviation ("NNE"). Points at static storage.
const char* hammy_compass_point(double bearingDeg);

#endif
