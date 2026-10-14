#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)

/* lq/sq quad copies and VU0 dot/negate/scale as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct VX : V { VX() {} VX(const VX& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VX ZeroX() { VX z; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&z) : "memory"); return z; }
static inline float Dot(const V* a, const V* b)
{
    int r;
    float ret = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(ret), "=&r"(r) : "r"(a), "r"(b) : "memory");
    return ret;
}
static inline void Neg1(V* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline void Neg(V* d, const V* s) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(s) : "memory"); }
static inline void ScaleTo(V* d, const V* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V* d, const V* v, float k) { ScaleTo(d, v, k); }
static inline V Scaled(const V& v, float k)
{
    V r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V* d, const V& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V a;
    V b;
    float t;
    void Set(const V& na, const V& nb) { V* p = &a; V* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V& a, const V& z, float t) { s->Set(a, Scaled(z, t)); }
struct VY : V { VY() {} VY(const VY& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VY ZeroY() { VY z; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&z) : "memory"); return z; }
static inline VY ZeroWY() { return ZeroY(); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam310 {
    char pad0[0x20];
    V p20;
    V p30;
    V p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
    char padB8[8];
    unsigned char bC0;
};

extern "C" {
void func_0017D7F0(void* p, int f);
void* func_00139BC0(int size, void* p);
void func_0017D700(void* p, V* a, V* b, V* c, V* d, float t);
}

extern "C" void func_00180310(Cam310* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        if (c->bC0) {
            V* p = &c->p40;
            if (Dot(p, &c->p20) < 0.0f)
                Neg1(p);
        }
        VX z = ZeroX();
        func_0017D7F0(&c->sp, -1);
        void* p = func_00139BC0(0x50, &c->sp);
        if (p)
            func_0017D700(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            if (c->bC0) {
                const V* pa = &c->sp.a;
                if (Dot(&c->p40, pa) < 0.0f)
                    Neg(&c->p40, &c->p40);
            }
            VY z = ZeroWY();
            __int128 tt = 0; /* dead paddub */
            SetSc(&c->sp, c->p40, z, c->sp.t);
        }
    }
}






