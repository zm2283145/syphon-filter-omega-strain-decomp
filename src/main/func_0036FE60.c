#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_36FE60;
typedef struct { V4_36FE60 r[4]; } M_36FE60;
static inline M_36FE60* QuatToMtx_36FE60(M_36FE60* a, V4_36FE60* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}
static inline void MulRot_36FE60(M_36FE60* s, M_36FE60* d, M_36FE60* r)
{
    asm {
        lqc2 vf4, 0x0(r)
        lqc2 vf5, 0x10(r)
        lqc2 vf6, 0x20(r)
        lqc2 vf8, 0x0(s)
        lqc2 vf9, 0x10(s)
        lqc2 vf10, 0x20(s)
        lqc2 vf11, 0x30(s)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(d)
        sqc2 vf9, 0x10(d)
        sqc2 vf10, 0x20(d)
        sqc2 vf11, 0x30(d)
    }
}
#pragma opt_common_subs off
void cXform_Rotate_cQuaternionR(V4_36FE60* a, V4_36FE60* q)
{
    M_36FE60 rot;
    QuatToMtx_36FE60(&rot, q);
    MulRot_36FE60((M_36FE60*)(a + 1), (M_36FE60*)(a + 1), &rot);
}


