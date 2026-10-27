#pragma cplusplus on
#include "types.h"
#pragma always_inline on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V(const V& o) { V* pd = this; const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Edge { V a; V pad10; V b; V pad30; V n; };
static inline void Cross(V* r, const V* a, const V* b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void Sub(const V* a, V* r, const V* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(r)
    }
}
static inline void Normalize(V* a) { V* r = a;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(r)
    }
}
static inline float Dot3(const V* a, const V* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void Neg(V* r, const V* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(r)
        .set noreorder
        nop
        .set reorder
    }
}
static inline V CrossV(const V& a, const V& b) { V r; Cross(&r, &a, &b); return r; }
static inline V SubV(const V& a, const V& b) { V r; Sub(&a, &r, &b); return r; }
static inline void SetNormalized(V* d, V v) { *d = v; Normalize(d); }
static inline float DotV(const V& a, V b) { return Dot3(&a, &b); }
#pragma opt_common_subs off
extern "C" V CalculateUnitEdgeOutwardXYNormal(Edge* e)
{
    V n; const V& en = e->n; V up(0.0f, 0.0f, 1.0f, 0.0f);
    SetNormalized(&n, CrossV(en, up));
    if (DotV(n, SubV(e->b, e->a)) > 0.0f) Neg(&n, &n);
    return n;
}
