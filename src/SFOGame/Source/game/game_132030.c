/*
 * main/game: range (4 files, 00132030-001320F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vu0_ops.h"

/* merge_units: begin func_00132030 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Normalize_void(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq 
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132030 */

/* merge_units: begin func_00132060 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4 cVector_GetNormalized_void(V4 v) {
    V4* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132060 */

/* merge_units: begin func_001320B0 */
#pragma push /* merge_units */
int cVector_IsZeroXYZ(void* v) {
    return VU0_IsZero3(v);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001320B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001320B0 */

/* merge_units: begin func_001320F0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
V4 cVector_Cross(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001320F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001320F0 */
