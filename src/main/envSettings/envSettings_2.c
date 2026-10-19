/*
 * main/envSettings: 2 files, 00178420-00178440
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178420 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "envSettings_types.h"

EnvVec3* func_00178420(EnvVec3* dst, EnvVec3* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00178420 */

/* merge_units: begin func_00178440 */
#pragma push /* merge_units */
typedef struct { int a[4]; unsigned char active; float t; float dur; float frac; } S178;
void func_00178440(S178* s, float dt) {
    if (s->active) {
        s->t += dt;
        if (s->t < s->dur) {
            s->frac = s->t / s->dur;
        } else {
            s->t = 0.0f;
            s->dur = 0.0f;
            s->frac = 1.0f;
            s->active = 0;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00178440 */
