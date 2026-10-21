#pragma cplusplus on
#include "types.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Limit { V4 scale; V4 post; V4 pre; };
extern "C" {
int func_001D1100(V4* v);
void Quat_Assign(V4* d, V4* s);
float func_001CF640(V4* v);
float func_001CF630(V4* v);
float func_001CF620(V4* v);
float func_001CF650(V4* v);
float* func_001CF610(V4* v);
float* func_001CF600(V4* v);
float* func_001CF5F0(V4* v);
float* func_001CF5E0(V4* v);
V4* Vec4_Set(V4* v, float x, float y, float z, float w);
V4* Vec4_NormalizeXYZ_1D10C0(V4* v, float* len);
V4* Vec4_Assign(V4* d, const V4* s);
float func_001D10B0(float x);
float func_001D10A0(float a, float b);
float func_001D1080(float x);
float Vec4_GetX(V4* v);
float Vec4_GetY(V4* v);
float Vec4_GetZ(V4* v);
}
// 128-bit lq/sq quadword copy idiom
static inline void Cp(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
// 128-bit lq/sq quadword copy idiom
static inline void CpC(void* d, const void* s) { const void* p = s; __asm__ volatile("lq %0, 0x0(%0)" : "+r"(p)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(p), "r"(d) : "memory"); }
// 128-bit lq/sq quadword copy idiom
static inline void CpE(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
// VU0 macro-mode quaternion ops (COP2), not expressible in C
static inline void QMul(V4* o, const V4* b, const V4* c) {
    __asm__ volatile("lqc2 vf1, 0x0(%0)\n lqc2 vf2, 0x0(%1)\n vmul.xyzw vf3, vf1, vf2\n vopmula.xyz ACC, vf1, vf2\n vmaddaw.xyz ACC, vf1, vf2w\n vmaddaw.xyz ACC, vf2, vf1w\n vopmsub.xyz vf4, vf2, vf1\n vsubaz.w ACC, vf3, vf3z\n vmsubay.w ACC, vf0, vf3y\n vmsubx.w vf4, vf0, vf3x\n sqc2 vf4, 0x0(%2)" : : "r"(b), "r"(c), "r"(o) : "memory");
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Neg(V4* d, const V4* s) {
    asm {
        lqc2 vf1, 0(s)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0(d)
    }
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float WDot(const V4* a, const V4* b) { int t; float r = 0.0f; __asm__ volatile("lqc2 vf1, 0x0(%2)\n lqc2 vf2, 0x0(%3)\n vmul.xyz vf3, vf1, vf1\n vmul.xyz vf4, vf3, vf2\n vmulax.w ACC, vf0, vf4x\n vmadday.w ACC, vf0, vf4y\n vmaddz.w vf5, vf0, vf4z\n vdiv Q, vf0w, vf5w\n vwaitq\n vaddq.x vf6, vf0, Q\n qmfc2.ni %1, vf6\n mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory"); return r; }

extern "C" void func_001D0DF0(V4* out, V4* q, int flag, Limit* lim)
{
    float len;
    V4 a, r2, t80, r, t60, axis, t40;
    V4* pb = &lim->pre;
    Cp(&a, q);
    V4* pa = &a;
    QMul(&r, pb, pa);
    { void* d2 = pa; const void* s2 = &r2; void* d1 = &r2; const void* s1 = &r; CpC(d1, s1); CpE(d2, s2); }
    if (flag && a.w < 0.0f) {
        Neg(&a, &a);
    }
    if (func_001D1100(&a)) {
        Quat_Assign(out, &a);
    } else {
        float x = func_001CF640(&a);
        float y = func_001CF630(&a);
        float z = func_001CF620(&a);
        Vec4_Assign(&axis, Vec4_NormalizeXYZ_1D10C0(Vec4_Set(&t40, x, y, z, 0.0f), &len));
        float k = WDot(&axis, &lim->scale);
        if (func_001D10B0(len) > k || func_001CF650(&a) < 0.0f) {
            *func_001CF610(out) = func_001D1080(func_001D10A0(1.0f - k, 0.0f));
            float s = func_001D1080(k);
            *func_001CF600(out) = s * Vec4_GetX(&axis);
            *func_001CF5F0(out) = s * Vec4_GetY(&axis);
            *func_001CF5E0(out) = s * Vec4_GetZ(&axis);
        } else {
            Quat_Assign(out, &a);
        }
    }
    QMul(&t60, &lim->post, out);
    { void* d2 = out; const void* s2 = &t80; void* d1 = &t80; const void* s1 = &t60; CpC(d1, s1); CpE(d2, s2); }
}





