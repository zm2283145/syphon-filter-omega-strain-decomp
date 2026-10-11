#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
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

V4 func_003B1450(S_3B1450* p) {
    if (p->on) return Scale_(&p->v, p->s);
    return p->v;
}
#pragma pop