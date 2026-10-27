/*
 * main/ska: range (2 files, 003B22F0-003B2340)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003B22F0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0xF0]; V4 v; } A_22F0;
static inline V4 Scale_(V4* v, float s) {
    V4 r; int t; V4* q = &r;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        .set reorder
    }
    return *q;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_AccumulatePos(A_22F0* a, V4* v, float s) {
    V4 u;
    V4* d;
    V4* e;
    V4* p;
    u = Scale_(v, s);
    d = &a->v; e = &a->v; p = &u;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B22F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B22F0 */

/* merge_units: begin func_003B2340 */
#pragma push /* merge_units */
void cBone_AnimationAccumulateRotation(V4* a, V4* b, float s) {
    int rv1;
    a = (V4*)((char*)a + 0x190);
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddx.xyzw vf1, vf2, vf3x
        sqc2 vf1, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2340 */
