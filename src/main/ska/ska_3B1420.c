/*
 * main/ska: range (3 files, 003B1420-003B14A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_003B1420 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 Vec4_Add_3B1420(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1420 */

/* merge_units: begin func_003B1450 */
#pragma push /* merge_units */
typedef struct { int f0; float s; unsigned char on; char pad[7]; V4 v; } S_3B1450;
static inline V4 Scale_(V4* v, float s) {
    V4 r;
    V4* q = &r;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        
    }
    return *q;
}
#pragma push
#pragma peephole off

V4 cSkaPlaybackItem_GetSummedOffsetRootRotation(S_3B1450* p) {
    if (p->on) return Scale_(&p->v, p->s);
    return p->v;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1450 */

/* merge_units: begin func_003B14A0 */
#pragma push /* merge_units */
typedef struct { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B14A0;
AC_3B14A0* cSkaPlaybackItem_opAssign(AC_3B14A0* self, AC_3B14A0* o) {
    self->id = o->id;
    self->weight = o->weight;
    self->active = o->active;
    { typedef char uf_chk_[sizeof(self->v) == 16 ? 1 : -1]; VCopyF(&(self->v), &(o->v)); }
    return self;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B14A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B14A0 */
