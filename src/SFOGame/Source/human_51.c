/*
 * SFOGame/Source/human: 1 file, 00197500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00197500 */
#pragma push /* merge_units */
#include "types.h"

extern void cNetMsg_GetFloat_floatR(float* out);

/* Fills a point from three successive cNetMsg_GetFloat_floatR reads (x, y, z) with w = 1. */
void cNetMsg_GetVector(Vec4* out) {
    float z, y, x;
    cNetMsg_GetFloat_floatR(&x);
    out->x = x;
    cNetMsg_GetFloat_floatR(&y);
    out->y = y;
    cNetMsg_GetFloat_floatR(&z);
    out->z = z;
    out->w = 1.0f;
}
static inline void merge_flush_func_00197500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00197500 */
