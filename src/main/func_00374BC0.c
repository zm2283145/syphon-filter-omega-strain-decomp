#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V a, b, c, d;
    M() {}
    M(const M& o) { void* xx = this; __int128 qa; __int128 qb; M* d = this; const M* s = &o;  __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MM(M* d, const M* a, const M* b) { __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline M operator*(const M& a, const M& b) { M r; const M* pb = &b; M* d = &r; const M* pa = &a; MM(d, pa, pb); return r; }
static inline void MulM(V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V XformPt(const V& v, const M& m) { V p = v; V* pp = &p; MulM(pp, &m); return *pp; }
static inline V Project(const V& v, const M& m) { return XformPt(v, m); }
struct Cam { float x, y, w, h; char pad10[0x40]; M m; char pad90[0x64]; float nearz; float pad; float farz; };
extern "C" M D_00539070;
extern "C" V cXViewport_GetScreenVert(Cam* c, const V* p)
{
    V sc;
    float hz = 0.5f * (c->farz - c->nearz);
    sc.x = c->w / 2.0f;
    sc.y = c->h / 2.0f;
    sc.z = hz;
    sc.w = 1.0f;
    V off;
    off.x = (c->x + 0.5f * c->w) + 0.5f * -c->w;
    off.y = (c->y + 0.5f * c->h) + 0.5f * -c->h;
    off.z = hz + c->nearz;
    off.w = 0.0f;
    M m = c->m * D_00539070;
    V r = Project(*p, m);
    float k = 1.0f / r.w;
    r.x *= k * sc.x;
    r.y *= k * sc.y;
    r.z *= k * sc.z;
    r.w = 1.0f;
    r.x += off.x;
    r.y += off.y;
    r.z += off.z;
    return r;
}












