/*
 * SFOGame/Source/humanIk: 2 files, 001D10C0-001D1100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D10C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Normalize_floatR(V4* v, float* len) {
    int t;
    asm {
        lqc2 vf1, 0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(v)
        qmfc2.ni t, vf4
    }
    *(int*)len = t;
    return v;
}
static inline void merge_flush_func_001D10C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D10C0 */

/* merge_units: begin func_001D1100 */
#pragma push /* merge_units */
#include "vu0_ops.h"
int cQuaternion_IsZeroXYZ(void* v) {
    return VU0_IsZero3(v);
}
static inline void merge_flush_func_001D1100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D1100 */
