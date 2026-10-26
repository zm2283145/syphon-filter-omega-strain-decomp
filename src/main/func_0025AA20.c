#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* SegmentIntersectsSphere: does the segment a-b pass within radius r of point c */
struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const;
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
} __attribute__((aligned(16)));
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
inline V V::operator-(const V& o) const { V r; SubV(&r, this, &o); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(const V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// VU0 macro-mode dot product (COP2), not expressible in C
static inline float Dot3(const V* a, const V* b)
{
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
extern "C" int SegmentIntersectsSphere(V* a, V* b, V* c, float r);
static inline float LenSq0(const V* a) { return LenSq(a); }
static inline float LenSqV(V v) { return LenSq0(&v); }
int SegmentIntersectsSphere(V* a, V* b, V* c, float r)
{
    
    V ac = *c - *a;
    float r2 = r * r;
    float d2 = LenSq(&ac);
    if (d2 < r2 || LenSqV(*c - *b) < r2) return 1;
    V ab = *b - *a;
    float len = Len(&ab);
    V dir = ab * (1.0f / len);
    float t = Dot3(&ac, &dir);
    if (t > 0.0f && t < len && d2 - t * t < r2) return 1;
    return 0;
}
