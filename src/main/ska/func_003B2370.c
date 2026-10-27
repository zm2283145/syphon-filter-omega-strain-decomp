#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0xE0]; V4 acc; char pad2[0x60]; V4 q; } A_2370;
static inline float Dot_2370(V4* a, V4* b) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline V4 Scale_2370(V4* v, float s) {
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
static inline void ScaleTo_2370(V4* out, V4* v, float s) {
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
        pd = out;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q));
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory");
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_AccumulateRot(A_2370* a, V4* v, unsigned char flag, float s) {
    if (!flag || Dot_2370(v, &a->q) >= 0.0f) {
        V4 u;
        V4* d;
        V4* e;
        V4* p;
        u = Scale_2370(v, s);
        d = &a->acc; e = &a->acc; p = &u;
        asm {
            lqc2 vf1, 0x0(e)
            lqc2 vf2, 0x0(p)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
    } else {
        V4 u;
        V4* d;
        V4* e;
        V4* p;
        ScaleTo_2370(&u, v, s);
        d = &a->acc; e = &a->acc; p = &u;        asm {
            lqc2 vf1, 0x0(e)
            lqc2 vf2, 0x0(p)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
    }
}
#pragma pop


