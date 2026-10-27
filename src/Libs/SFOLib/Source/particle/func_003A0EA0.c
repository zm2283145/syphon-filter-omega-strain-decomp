#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"

struct W_0EA0 { int x, y, z, w; W_0EA0() {} W_0EA0(const W_0EA0& o) { x = o.x; y = o.y; z = o.z; w = o.w; } W_0EA0& operator=(const W_0EA0& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };

struct V_0EA0 {
    float x, y, z, w;
    V_0EA0() {}
    V_0EA0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_0EA0(const V_0EA0& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    void Set(const V_0EA0& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V_0EA0& operator=(const V_0EA0& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct M_0EA0 {
    V_0EA0 r0, r1, r2, r3;
    M_0EA0() {}
    M_0EA0& operator=(const M_0EA0& o) { void* xx = this; __int128 qa; __int128 qb; M_0EA0* d = this; const M_0EA0* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M_0EA0(const M_0EA0& o) { __int128 qa; __int128 qb; const M_0EA0* s = &o; M_0EA0* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

/* VU0 4x4 matrix multiply, in place into d */
static inline void MulM_0EA0(M_0EA0* d, const M_0EA0* a)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "lqc2 $vf8, 0x0(%0); lqc2 $vf9, 0x10(%0); lqc2 $vf10, 0x20(%0); lqc2 $vf11, 0x30(%0)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(a) : "memory");
}
static inline M_0EA0& MulInto_0EA0(M_0EA0* t, const M_0EA0* a) { M_0EA0* p = t; MulM_0EA0(p, a); return *p; }

/* VU0 3x3 rotate of a vector by a matrix */
static inline void Rot_0EA0(V_0EA0* o, const V_0EA0* v, const M_0EA0* m)
{
    __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}
/* VU0 vector length */
static inline float Len_0EA0(const V_0EA0* pv)
{
    float ret = 0.0f;
    int t;
    /* zero init as C */
    asm {
        lqc2 vf1, 0(pv)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, ret
    }
    return ret;
}
/* VU0 distance between two vectors */
static inline float DistIn_0EA0(V_0EA0& d, const V_0EA0& a, const V_0EA0& b)
{
    V_0EA0 r;
    float ret;
    {
        V_0EA0* pr = &r;
        const V_0EA0* pa = &a;
        const V_0EA0* pb = &b;
        asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    }
        {
            V_0EA0* dd;
            const V_0EA0* ss;
            int t;
            __int128 x;
            V_0EA0* pv;
            ss = &r;
            pv = &d; /* assigned twice on purpose: retail keeps the first one */
            ret = 0.0f;
            pv = &d;
            dd = &d;
            x = *(__int128*)ss;
            *(__int128*)dd = x;
            asm {
                lqc2 vf1, 0(pv)
                vmul.xyz vf2, vf1, vf1
                vmulax.w ACC, vf0, vf2x
                vmadday.w ACC, vf0, vf2y
                vmaddz.w vf3, vf0, vf2z
                vsqrt Q, vf3w
                vwaitq
                vaddq.x vf4, vf0, Q
                qmfc2.ni t, vf4
                mtc1 t, ret
            }
        }
    return ret;
}

static inline float Dist_0EA0(const V_0EA0& a, const V_0EA0& b)
{
    V_0EA0 d;
    return DistIn_0EA0(d, a, b);
}

struct Def_0EA0 {
    char pad0[0x14];
    float x14;
    char pad18[0x60 - 0x18];
    unsigned int x60;
    char pad64[0x8B0 - 0x64];
    M_0EA0 m;               /* 0x8B0 */
    char pad8F0[0xA34 - 0x8F0];
    float xA34;
    float xA38;
    unsigned int xA3C;
    V_0EA0 pts[3];          /* 0xA40 */
};
struct Obj_0EA0 {
    void* vt;
    char pad4[0xC];
    M_0EA0 m;               /* 0x10 */
    V_0EA0 v50;             /* 0x50 */
    float x60;
    char pad64[0x90 - 0x64];
    V_0EA0 a[7];            /* 0x90 */
    Def_0EA0* def;          /* 0x100 */
    char pad104[0xC];
    V_0EA0 b[3];            /* 0x110 */
    V_0EA0 c[3];            /* 0x140 */
    float len[3];           /* 0x170 */
};
#define V30(s) (*(V_0EA0*)((char*)(s) + 0x30))
#define V40(s) (*(V_0EA0*)((char*)(s) + 0x40))

extern "C" Obj_0EA0* cParticleBase_ctor(Obj_0EA0* self, Obj_0EA0* parent, Def_0EA0* def, float f);
extern "C" void cParticleSpline_ComputeBezierFactors(Obj_0EA0* self, V_0EA0* pts, V_0EA0* out);
extern void* const D_004DFB30[];
extern W_0EA0 D_00538350;

static inline void Compose3_0EA0(Obj_0EA0* self, Obj_0EA0* parent, M_0EA0* m, M_0EA0& r)
{
    M_0EA0* pm;
    M_0EA0 t = *m;
    const M_0EA0* pa = &parent->m;
    M_0EA0& rr = (r = MulInto_0EA0(&t, pa));
    void* xx = &self->m;
    pm = &self->m;
    *pm = rr;
}

static inline void Compose2_0EA0(Obj_0EA0* self, Obj_0EA0* parent, M_0EA0* m, M_0EA0& r) { Compose3_0EA0(self, parent, m, r); }
static inline void Compose_0EA0(Obj_0EA0* self, Obj_0EA0* parent, M_0EA0* m, M_0EA0& r) { Compose2_0EA0(self, parent, m, r); }

extern "C" Obj_0EA0* cParticleSpline_ctor(Obj_0EA0* self, Obj_0EA0* parent, Def_0EA0* def, float f, M_0EA0* m)
{
    V_0EA0 p[3];
    M_0EA0 r;
    W_0EA0 c;
    cParticleBase_ctor(self, parent, def, f);
    self->vt = (void*)D_004DFB30;
    {
        V_0EA0* q = self->a;
        V_0EA0* e = self->a + 7;
        do { q++; } while (q != e);
    }
    {
        V_0EA0* q = self->b;
        do { q++; } while (q != self->b + 3);
    }
    {
        V_0EA0* q = self->c;
        do { q++; } while (q != self->c + 3);
    }
    self->def = def;
    if (!parent) {
        self->m = def->m;
    } else {
        Compose_0EA0(self, parent, m, r);
    }
    self->a[0] = V40(self);
    self->a[0].w = def->x14;
    self->a[2] = V30(self);
    self->a[2].w = (float)def->x60;
    c = D_00538350;
    *(W_0EA0*)&self->a[1] = c;
    self->x60 = 1.0f + (float)def->xA3C * (def->xA34 + def->xA38);
    p[0] = def->pts[0];
    Rot_0EA0(&p[0], &p[0], &self->m);
    p[1] = def->pts[1];
    Rot_0EA0(&p[1], &p[1], &self->m);
    p[2] = def->pts[2];
    Rot_0EA0(&p[2], &p[2], &self->m);
    self->b[0].Set(p[0]);
    self->b[1].Set(p[1]);
    self->b[2].Set(p[2]);
    self->c[0].Set(V_0EA0(0.0f, 0.0f, 0.0f, 0.0f));
    self->c[1].Set(V_0EA0(0.0f, 0.0f, 0.0f, 0.0f));
    self->c[2].Set(V_0EA0(0.0f, 0.0f, 0.0f, 0.0f));
    self->len[0] = Len_0EA0(&p[0]);
    self->len[1] = Dist_0EA0(p[1], p[0]);
    self->len[2] = Dist_0EA0(p[2], p[1]);
    cParticleSpline_ComputeBezierFactors(self, p, self->a + 4);
    return self;
}
