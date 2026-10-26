#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const { V t; V* q = &t; __int128 tt = 0; const V* p = this; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder } return t; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
extern "C" V cWind_GetTurbulence_float_float_float(const M* m, float x, float y, float z)
{
    V a;
    { V t = m->r[1] * x; a = t; }
    a += m->r[2] * y;
    a += m->r[3] * z;
    return a;
}


