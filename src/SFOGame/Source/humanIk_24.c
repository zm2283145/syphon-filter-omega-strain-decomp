/*
 * SFOGame/Source/humanIk: 1 file, 001D56E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D56E0 */
#pragma push /* merge_units */
#include "types.h"
typedef union { float f[4]; __int128 q; } V4;
static inline V4 neg4v_(V4* b) {
    V4 r; V4* p = &r;
    asm {
        lqc2 vf1, 0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0(p)
    }
    return r;
}
static inline void add3_(V4* d, V4* a, V4* b) {
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(d)
    }
}
#pragma push
#pragma opt_common_subs off
V4* cVector_InverseTranslate(V4* a, V4* b) {
    V4 n = neg4v_(b);
    add3_(a, a, &n);
    return a;
}
#pragma pop
static inline void merge_flush_func_001D56E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D56E0 */
