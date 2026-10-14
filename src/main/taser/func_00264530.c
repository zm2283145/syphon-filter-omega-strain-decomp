#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* lq/sq quad copies and VU0 vector ops as GCC-style volatile asm; the unused xx keeps retail's dead addiu.
   axis/up are declared before the scoped d so the stack slots match (up at 0x80, d at 0x70). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void VSub(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
struct M {
    V r[3]; V t;
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
};
struct Pt { V pos; V src; char pad[0x20]; };
struct Path {
    char pad[0x14];
    int n;
    Pt* p;
    char pad1C[0x60 - 0x1C];
    M m;
    Pt*& P() { return p; }
};
extern "C" {
V* func_00132000(V* v, float x, float y, float z, float w);
void Vec4_NormalizeXYZ_132060(V* out, V* v);
void Vec4_Cross(V* out, V* a, V* b);
V* Vec4_NormalizeXYZInPlace(V* v);
V* Vec4_Assign(V* d, V* s);
int Vec4_IsZeroXYZ(V* v);
void Mtx_FromRowsAndTranslation(M* m, V* a, V* b, V* c, V* t);
void Mtx_FrameFromAxis(M* m, V* axis);
void Mtx_SetIdentity(M* m);
}
extern "C" void func_00264530(Path* s, V* org)
{
    s->p[0].pos = *org;
    V axis;
    V up;
    {
        V d;
        VSub(&d, &(&s->P()[s->n])[-1].pos, &s->P()[0].pos);
        axis = d;
    }
    up.Set(0.0f, 0.0f, 1.0f, 1.0f);
    {
        V c;
    Vec4_Cross(&c, &axis, &up);
    if (!Vec4_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        Vec4_NormalizeXYZ_132060(&f, &axis);
        Vec4_Assign(&r, Vec4_NormalizeXYZInPlace(&c));
        Vec4_Cross(&u, &r, &f);
        Mtx_FromRowsAndTranslation(&s->m, &r, &f, &u, func_00132000(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!Vec4_IsZeroXYZ(&axis)) {
        Mtx_FrameFromAxis(&s->m, &axis);
    } else {
        Mtx_SetIdentity(&s->m);
    }
    }
    V* t = &s->m.t; *t = s->P()[0].pos;
    int n = s->n;
    for (int i = 0; i < n; i++) {
        s->P()[i].pos = s->P()[i].src;
        s->m.Apply(&s->P()[i].pos);
    }
}

