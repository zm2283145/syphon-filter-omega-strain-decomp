#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline V Sum(const V& a, const V& b);
struct V {
    float x, y, z, w;
    V() {}
    V(float r) { float rr = r; x = rr; y = rr; z = rr; w = 0.0f; }
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V(const V& a, float s) { __int128 t = 0; V* q = this; const V* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V operator*(float s) const { return V(*this, s); }
    V operator+(const V& b) const { return Sum(*this, b); }
    V operator-() const { V t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    void Add(const V& b) { V* d = this; const V* s = &b; asm volatile {
 lqc2 vf1, 0x0(d)
 lqc2 vf2, 0x0(s)
 vadd.xyz vf1, vf1, vf2
 sqc2 vf1, 0x0(d)
 } }
    void operator+=(const V& b) { const V* s = &b; V* d = this; asm volatile {
 lqc2 vf1, 0x0(d)
 lqc2 vf2, 0x0(s)
 vadd.xyz vf1, vf1, vf2
 sqc2 vf1, 0x0(d)
 } }
} __attribute__((aligned(16)));
static inline V Sum(const V& a, const V& b) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
struct Box { V lo, hi;
    Box() {}
    void Reset() { lo = V(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f); hi = V(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f); }
    Box(int) { lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f; hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f; }
    void Grow(float r) { V pad(r); lo += -pad; hi += pad; }
    void GrowB(float r) { V pad(r); lo.Add(-pad); hi += pad; }
    void Merge(const Box& b) { if (b.lo.x <= b.hi.x) { Extend(b.lo); Extend(b.hi); } }
    void Extend(const V& p) { V* l = &lo; V* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(&p) : "memory"); }
};

struct Sph {
    char pad0[0x20];
    float r;
    char pad24[0xC];
    V c;
    V off;
};
extern "C" {
void Camera_ZoomBounds(Sph* s, Box* out);
}
void Camera_ZoomBounds(Sph* s, Box* out)
{
    out->Reset();
    out->Extend(s->c);
    Box b(0);
    V p = s->c + s->off;
    b.Extend(p);
    b.GrowB(s->r);
    out->Merge(b);
    out->Grow(0.25f);
}







