#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct VX : V { VX(const V& o) { void* xx = this; const void* s = &o; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(this) : "memory"); } } __attribute__((aligned(16)));
static inline void ConjIP(V* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline VX Conj0(const V& q) { V r(q); V* p = &r; ConjIP(p); return *p; }
static inline VX Conj(const V& q) { return Conj0(q); }
static inline V QMul(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vmul.xyzw vf3, vf1, vf2; vopmula.xyz ACC, vf1, vf2; vmaddaw.xyz ACC, vf1, vf2w; vmaddaw.xyz ACC, vf2, vf1w; vopmsub.xyz vf4, vf2, vf1; vsubaz.w ACC, vf3, vf3z; vmsubay.w ACC, vf0, vf3y; vmsubx.w vf4, vf0, vf3x; sqc2 vf4, 0x0(%2)" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline void SetP(V* d, const V& o) { const void* s = &o; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline void SetP2(V* d, const V* o) { const void* s = o; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline void SetP3(V* d, const V& o) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : : "r"(&o), "r"(d) : "memory"); }
static inline V Mul(const V& a, VX b) { V* p = &b; const V* pa = &a; SetP(p, QMul(*pa, *p)); return *p; }
static inline float Dot(const V* a, const V* b)
{
    int r;
    float ret = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(ret), "=&r"(r) : "r"(a), "r"(b) : "memory");
    return ret;
}
static inline void Neg(V* d, const V* s) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(s) : "memory"); }
static inline V Sub(const V& a, const V& b)
{
    V r; V* pr = &r; const V* pa = &a; const V* pb = &b;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%2)" : : "r"(pa), "r"(pb), "r"(pr) : "memory");
    return r;
}
static inline void ScaleTo(V* d, const V* v, float k)
{
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline V Scaled(const V& v, float k)
{
    V r;
    ScaleTo(&r, &v, k);
    return r;
}
static inline float Max(float a, float b)
{
    float r = 0.0f;
    asm { max.s r, a, b }
    return r;
}

struct Motion {
    char pad0[0x10];
    V prev;
    V rot;
    V vel;
    char pad40[0x10];
    float damping;
    char pad54[0x6C];
    unsigned char shortest;
};

extern "C" void cSplinedMotion_QuaternionLERP_1_UpdateVelocity(Motion* m, float timeStep, float oneOverTimeStep)
{
    V deltaRot = Mul(m->rot, Conj(m->prev));
    V projectedRot = QMul(deltaRot, m->rot);
    if (m->shortest) {
        if (Dot(&projectedRot, &m->rot) < 0.0f)
            Neg(&projectedRot, &projectedRot);
    }
    m->vel = Scaled(Sub(projectedRot, m->rot), oneOverTimeStep);
    ScaleTo(&m->vel, &m->vel, Max(0.0f, 1.0f - m->damping * timeStep));
}








