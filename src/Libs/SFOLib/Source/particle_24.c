/*
 * Libs/SFOLib/Source/particle: 1 file, 003A5E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A5E20 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003A5E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A5E20 */
