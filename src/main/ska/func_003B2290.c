#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x110]; V4 v[1]; } A_2290;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void AnimRoot_AccumMotion(A_2290* a, V4* v, unsigned char i, float s) {
    V4 u;
    V4* d;
    V4* e;
    V4* p;
    {
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
        {
            V4* pd;
            __int128 t2;
            pd = &u;
            __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q));
            __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory");
        }
    }
    p = &u; d = (V4*)((char*)&a->v[0] + (i << 4)); e = d;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma pop
