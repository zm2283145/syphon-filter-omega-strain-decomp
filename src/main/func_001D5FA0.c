// func_001D5FA0: like func_001D5E90, but also composes the rotation with the parent quaternion (VU0).
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_propagation off

static inline void Add_(void* d, const void* o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(o) : "memory"); }
static inline void Add2_(void* d, const void* o) { Add_(d, o); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& Rotate(const V& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
    void Add3(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); }
    V operator*(float k) const;
    void AddP(V o) { const void* po = &o; Add2_(this, po); float* pw = &w; *pw = o.w; }
} __attribute__((aligned(16)));

struct Xf {
    V a;
    V rot;
    V pos;
    V& Pos() { Xf* t = this; return t->pos; }
    V& A() { Xf* t = this; return t->a; }
    V& Rot() { Xf* t = this; return t->rot; }
};
struct Src { char pad[0x1B0]; V v; V& Get() { return v; } };
struct Obj {
    Src* src;
    char pad4[0xBC];
    Obj* parent;
    char padC4[0xC];
    Xf xf;
};

static inline V QMul(const V* a, const V* b)
{
    V l0;
    V* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}

static inline V QW(const V* a, const V* b) { return QMul(a, b); }
static inline V QW2(const V* a, const V* b) { return QW(a, b); }
// .set noreorder keeps the VU0 block intact (retail ends it with the scheduler nop).
static inline void ScaleTo(V* d, const V* s, float k) { int r; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
static inline void Apply(const V& prot, const V& ppos, V& p)
{
    p.Rotate(prot);
    float* w = &p.w;
    float wv = *w;
    if (wv == 1.0f) {
        p.Add3(ppos);
    } else {
        p.AddP(ppos * wv);
    }
}

extern "C" void func_001D5FA0(Obj* o)
{
    o->xf.Rot() = o->xf.A();
    o->xf.Pos() = o->src->Get();
    if (o->parent) {
        Obj* pa = o->parent; V& r = o->xf.Rot(); r = QW2(&pa->xf.Rot(), &r);
        Apply(o->parent->xf.Rot(), o->parent->xf.Pos(), o->xf.Pos());
    }
}
