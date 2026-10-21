#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline V Sum(const V& a, const V& b);
struct V {
    float x, y, z, w;
    V() {}
    V(const float& r, float m) { float mm = m; x = r + mm; y = r + mm; z = r + mm; w = 0.0f; }
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V(const V& a, float s) { __int128 t = 0; V* q = this; const V* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V operator*(float s) const { return V(*this, s); }
    V operator+(const V& b) const { return Sum(*this, b); }
    V operator-() const { V t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    void operator+=(const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V Sum(const V& a, const V& b) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
struct Box { V lo, hi;
    void Extend(const V& p) { V* l = &lo; V* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(&p) : "memory"); }
};
extern "C" void* VecList_GetData(void* self);
struct It { V* p; It() {} It(const It& o) { p = o.p; } };
static inline bool operator==(const It& a, const It& b) { V* y = b.p; V* x = a.p; return x == y; }
static inline bool operator!=(const It& a, const It& b) { return !(a == b); }
struct VecList {
    int f0; int n; V* data;
    It begin() { It t; t.p = *(V**)VecList_GetData(this); return t; }
    It end() { It t; t.p = *(V**)VecList_GetData(this) + n; return t; }
};
struct CameraCol {
    char pad0[0x10];
    V ext;
    char pad20[0x10];
    VecList pts;
    char pad3C[4];
    V a;
    V b;
};
static inline void Grow(Box* out, const V& pad) { out->lo += -pad; out->hi += pad; }
extern "C" {
extern float D_004A3F60;
void CameraCol_ComputeBounds(CameraCol* c, Box* out);
}
void CameraCol_ComputeBounds(CameraCol* c, Box* out)
{
    V off; off = V(c->ext, D_004A3F60);
    out->lo = V(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    out->hi = V(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    for (It it = c->pts.begin(), e = c->pts.end(); it != e; it.p++) {
        V p = *it.p + off;
        out->Extend(p);
    }
    out->Extend(c->a);
    out->Extend(c->b);
    Grow(out, V(D_004A3F60, 0.25f));
}










