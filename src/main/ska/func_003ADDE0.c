#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Obj3ADDE0 { char p0[8]; unsigned char b8; char p9[7]; V v10; };
static inline int IsZero(const V* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void NormQ(V* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyzw vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddaz.w ACC, vf0, vf2z
        vmaddw.w vf3, vf0, vf2w
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyzw vf4, vf1, Q
        sqc2 vf4, 0x0(a)
    }
}
static inline void Unit(V* a) {
    asm { sqc2 vf0, 0x0(a) }
}
extern "C" V cSkaPlaybackItem_GetSummedAndNormalizedOffsetRootRotation(Obj3ADDE0* o)
{
    if (o->b8) return o->v10;
    if (!IsZero(&o->v10)) {
        V t = o->v10;
        V* p = &t;
        NormQ(p);
        return *p;
    }
    V r;
    Unit(&r);
    return r;
}
