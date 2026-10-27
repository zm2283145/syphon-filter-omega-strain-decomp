/*
 * SFOGame/Source/human: 1 file, 001A3170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A3170 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x2E4]; float f2E4; char pad2E8[0x310 - 0x2E8]; V4 pos; char pad320[0x10]; V4 vel; } H_3170;
#pragma peephole off
#pragma opt_common_subs off
#pragma opt_propagation off
void cHumanCollisionRoutine_PredictNextVelocity(V4* out, H_3170* h, float t)
{
    V4 b;
    V4 v;
    V4 m1;
    V4 m2;
    V4 res;
    V4* d; __int128 t1;
    V4* d2; __int128 t2;
    __int128 tt; V4* p;
    V4* q1 = &m1;
    V4* q2;
    { V4* p = &h->vel; float k = h->f2E4; int tt; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q1); .set reorder } }
    { d = &v; t1 = V4Load(q1); q2 = &m2; asm { paddub tt, zero, zero } *(__int128*)d = t1; p = &v; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, t; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q2); .set reorder } }
    { t2 = *(__int128*)q2; d2 = &b; *(__int128*)d2 = t2; }
    { V4* d = &res; V4* a = &h->pos; V4* bb = &b; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(bb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    *out = res;
}
static inline void merge_flush_func_001A3170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A3170 */
