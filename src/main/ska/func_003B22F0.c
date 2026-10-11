#include "types.h"
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
void AnimRoot_AccumPose(A_22F0* a, V4* v, float s) {
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