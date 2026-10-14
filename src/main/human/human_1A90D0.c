/*
 * main/human: range (3 files, 001A90D0-001A91A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vu0_quat_rot.h"

/* merge_units: begin func_001A90D0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4* func_001A90D0(V4* v, V4* qp) {
    V4 u; V4 t;
    V4* d1;
    V4* q2;
    V4* c;
    V4* d2;
    d1 = &t; c = &t; *d1 = *qp;
    VU0_NEG3(c, c)
    d2 = &u; q2 = &u; *d2 = *c;
    VU0_QROT(v, q2, v)
    return v;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A90D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A90D0 */

/* merge_units: begin func_001A9160 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
V4 func_001A9160(V4* b, V4* c, float s) {
    V4 l0;
    V4* q1 = &l0;
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A9160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A9160 */

/* merge_units: begin func_001A91A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float pos[4]; char pad2[0x30]; } PlaceD4;
typedef struct { PlaceD4 world; PlaceD4 base; } RootIdD4;
extern void* Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern RootIdD4* Root_Identity(void* r);
float* Root_GetWorldBasePlacement(void* r)
{
    PlaceD4* p;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        p = &Root_Identity(r)->world;
    } else {
        p = &Root_Identity(r)->base;
    }
    return p->pos;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A91A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A91A0 */
