#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_2530;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
P_2530* func_00132530(P_2530* p, V4* q) {
    V4 u; V4 t;
    V4* vp;
    V4* s2;
    V4* rq;
    V4* s1x;
    V4* d1;
    rq = &t;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(rq)
    }
    d1 = &u;
    vp = &p->pos;
    s2 = &u;
    s1x = &t;
    *d1 = *s1x;
    p->rot = *s2;
    VU0_QROT(vp, q, vp)
    return p;
}
#pragma pop