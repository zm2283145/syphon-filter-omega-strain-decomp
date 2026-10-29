#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
static inline void Q16(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* p = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o) : "memory"); *(__int128*)p = q; }
} __attribute__((aligned(16)));
static inline V4 Sub(const V4& a, const V4& b) {
    V4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void AddV(V4* r, const V4* a, const V4* b) {
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline V4 Add(const V4& a, const V4& b) { V4 r; AddV(&r, &a, &b); return r; }
static inline V4 Mul(const V4& v, float k) {
    V4 r; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(&r), "r"(&v), "f"(k) : "memory");
    return r;
}
static inline float LenSq(V4* v) {
    float r = 0.0f; int t;
    asm {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
extern "C" V4 PlayerInput_SmoothAimVector(V4* a, V4* b, float f, float lim, float g);
V4 PlayerInput_SmoothAimVector(V4* a, V4* b, float f, float lim, float g)
{
    V4 d = Sub(*a, *b);
    if (LenSq(&d) >= lim) {
        float s = Min(1.0f, f * g);
        V4 t = Mul(d, s);
        V4 r = Add(*b, t);
        return r;
    }
    return *a;
}
