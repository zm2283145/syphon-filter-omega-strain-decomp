#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
struct Sphere { int w0; unsigned char b4; char pad5[3]; float r; int wC; V c; };
static inline V Sub(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
static inline V Add(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
static inline void Union(Box* bx, const V& p0) {
    V* mx = &bx->mx; const V* p = &p0;
    asm {
        lqc2 vf1, 0x0(bx)
        lqc2 vf2, 0x0(mx)
        lqc2 vf3, 0x0(p)
        vmini.xyz vf1, vf1, vf3
        vmax.xyz vf2, vf2, vf3
        sqc2 vf1, 0x0(bx)
        sqc2 vf2, 0x0(mx)
    }
}
static inline void Xform(V& o, const V& in, M* m) {
    o = in;
    V* out = &o;
    asm {
        lqc2 vf8, 0x0(out)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(out)
    }
}
extern "C" void cSkeletonBBoxContribution_ContributeToBBox(Sphere* s, Box* box, M* m)
{
    V c = s->c;
    if (!s->b4)
        Xform(c, s->c, m);
    else
        c = m->r[3];
    if (s->r > 0.0f) {
        V rv(s->r, s->r, s->r, 0.0f);
        Union(box, Sub(c, rv));
        Union(box, Add(c, rv));
    } else {
        Union(box, c);
    }
}
