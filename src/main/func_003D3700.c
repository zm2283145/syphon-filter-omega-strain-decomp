#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void Q3700(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q3700(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Applied(V v) const { V* p = &v; Apply(p); return *p; }
};
struct Renderer { char pad0[0x180]; float f180; char pad184[0xC]; float f190; char pad194[0xF00 - 0x194]; M view; };
extern "C" void XLib_UpdateCompMat(Renderer* r);
static inline float MaxF(float a, float b) { return a > b ? a : b; }
static inline float MinF(float a, float b) { return a < b ? a : b; }
extern "C" float XLib_GetFogVal(Renderer* r, const V* p)
{
    XLib_UpdateCompMat(r);
    const M* m = &r->view;
    V v = m->Applied(*p);
    float f = r->f180 + r->f190 / v.w;
    return MinF(MaxF(f, 0.0f), 255.0f);
}

