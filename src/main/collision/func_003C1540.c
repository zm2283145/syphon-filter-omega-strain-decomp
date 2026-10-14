#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* VU0 ops as GCC-style asm; `.set noreorder` drops the assembler mfc1 hazard nop (retail has none).
   Dead `x1`/`x2` address locals give retail's dead addiu before the named-local copies. */
static inline float DotR_(const void* a, const void* b) {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%3); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory");
        return r;
}
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    float DotR(const V& b) const { const V* ap = this; return DotR_(ap, &b); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Flags {
    unsigned char bf;
    int K() const { return bf & ~0x80; }
};
static inline int Km(const unsigned char& c) { return c & ~0x80; }
struct Edge { V p0; V p1; char pad20[0x10]; Flags fl; char pad31[3]; float len; char pad38[8]; V n; };
extern "C" {
int func_003C14F0(Edge* a, Edge* b, float eps);
V* func_003C14E0(Edge* e);
V* func_003C14D0(Edge* e);
V* func_003C13B0(Edge* e);
float func_003C13C0(const V* a, const V* b, const V* dir);
float Math_MaxF(float a, float b);
bool ColEdge_AreConnected(Edge* a, Edge* b, float eps, float maxd, float tol);
}
bool ColEdge_AreConnected(Edge* a_, Edge* b_, float eps, float maxd, float tol)
{
    Edge* bb = b_;
    Edge* aa = a_;
#define a aa
#define b bb
    bool r = false;
    Flags fa;
    Flags fb;
    fb.bf = b->fl.bf;
    fa.bf = a->fl.bf;
    const Flags* pa = &fa;
    if ((pa->bf & ~0x80) == (fb.bf & ~0x80)) {
        bool ok;
        if (func_003C14F0(a, b, eps))
            ok = Math_MaxF(func_003C13C0(func_003C14E0(b), func_003C14E0(a), func_003C14D0(a)),
                      func_003C13C0(func_003C13B0(b), func_003C14E0(a), func_003C14D0(a))) <= maxd;
        else ok = false;
        if (ok) {
            V d0 = b->p0 - a->p0;
                        float t0 = a->n.DotR(d0);
            V d1 = b->p1 - a->p0;
                        float t1 = a->n.DotR(d1);
            float len = a->len;
            if (t0 >= -tol && t0 <= len + tol) r = true;
            else if (t1 >= -tol && t1 <= len + tol) r = true;
        }
    }
    return r;
}