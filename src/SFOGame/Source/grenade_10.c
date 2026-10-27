/*
 * SFOGame/Source/grenade: 1 file, 0025D430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025D430 */
#pragma push /* merge_units */
#include "types.h"
float D_0048AF70 __attribute__((aligned(8))) = 0.100000002f;
float D_0048AF78 __attribute__((aligned(8))) = 0.7f;
float cGrenade_FigureThrowAngle(float t) {
    if (t > 1.0f) t = 1.0f;
    return D_0048AF70 + t * (D_0048AF78 - D_0048AF70);
}
static inline void merge_flush_func_0025D430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025D430 */
