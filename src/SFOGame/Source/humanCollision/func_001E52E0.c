#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* the vadd sits two inline levels below operator+= so its pointer gets the register retail uses */
static inline void Add52_(void* d, const void* o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%0); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(o), "r"(d) : "memory"); }
static inline void Add52(void* d, const void* o) { Add52_(d, o); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); }
    V operator-() const { V t; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    V& operator+=(V o) { Add52(this, &o); return *this; }
    V& Rotate(const V& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" V cQuaternion_GetConjugate(const V& q);
extern "C" V* Quat_InverseTransformPoint(V* p, const V* q, const V* t)
{
    *p += -*t;
    V* r = p;
    V c = cQuaternion_GetConjugate(*q);
    { void* xx = &c; }
    r->Rotate(c);
    return r;
}

