#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void QD3D0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ QD3D0(this, &o); }
    V& operator=(const V& o) { QD3D0(this, &o); return *this; }
    V operator-() const { V t; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%0); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&o), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V min; V max; };
extern "C" void cBox_Grow(Box* b, float rad)
{
    V r(rad, rad, rad, 0.0f);
    b->min += -r;
    { void* xx = &b->max; /* dead on purpose: retail keeps this addiu */ }
    b->max += r;
}

