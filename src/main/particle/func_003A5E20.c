/*
 * Matched functions (byte-identical with the retail executable).
 * Vector-argument forwarder.
 */

#include "types.h"
#include "particle_types.h"

extern void cWind_GetTurbulence_float_float_float(int a0, int a1, float x, float y, float z);

/* Unpacks the vector v and forwards to cWind_GetTurbulence_float_float_float. */
void cWind_GetTurbulence_cVectorR(int a0, int a1, float* v) {
    float y = v[1];
    float z = v[2];
    float x = v[0];

    cWind_GetTurbulence_float_float_float(a0, a1, x, y, z);
}
