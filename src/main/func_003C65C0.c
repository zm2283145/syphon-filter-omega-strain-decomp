#pragma cplusplus on
#include "types.h"
static inline void Q65C0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Box { V min; V max; };
struct Sphere { float r; int pad[3]; V c; };
extern "C" void func_003C65C0(Sphere* out, const Box* b)
{
    V Lv; V c; V v; V sub; V sum; V t;
    float r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&sum), "r"(&b->max), "r"(&b->min) : "memory");
    {
        V* e; __int128 c2; float k; __int128 tt; const V* s; V* p; __int128 cq; V* d; V* q;
        void* xx = &v;
        tt = 0;
        s = &sum;
        d = &v;
        p = &v;
        q = &t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(cq) : "r"(d), "r"(s) : "memory");
        k = 0.5f;
        __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%0); qmtc2.ni %2, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : : "r"(p), "r"(q), "r"(k) : "memory");
        e = &c; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(c2) : "r"(e), "r"(q) : "memory");
    }
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&sub), "r"(&b->max), "r"(&b->min) : "memory");
    {
        V* e3; __int128 c3; float len; void* xx; const V* s; V* lp;
        s = &sub;
        xx = &Lv;
        lp = &Lv;
        len = 0.0f;
        e3 = &Lv; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(c3) : "r"(e3), "r"(s) : "memory");
        __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(lp) : "memory");
        r = 0.5f * len;
    }
    out->r = r;
    { void* xx = &out->c; Q65C0(&out->c, &c); }
}

