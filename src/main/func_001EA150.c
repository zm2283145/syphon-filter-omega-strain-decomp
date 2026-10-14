#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
static inline V4* NormXYZ_(V4* v, float* len) {
    int t;
    asm {
        lqc2 vf1, 0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(v)
        qmfc2.ni t, vf4
    }
    *(int*)len = t;
    return v;
}
extern "C" void Vec4_NormalizeXYZ_Div(V4* out, V4* in, float* len);
void Vec4_NormalizeXYZ_Div(V4* out, V4* in, float* len)
{
    V4 t;
    V4* p = &t;
    { V4* d = &t; __int128 q; asm volatile { lq q, 0(in); sq q, 0(d) } }
    __int128 tt = 0; /* dead: retail's paddub zero */
    NormXYZ_(p, len);
    { __int128 q; asm volatile { lq q, 0(p); sq q, 0(out) } }
}


