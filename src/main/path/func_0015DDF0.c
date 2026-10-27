#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline void VSub(void* r, const void* a, const void* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const { V c; VSub(&c, this, &b); return c; }
} __attribute__((aligned(16)));
struct PNode;
struct Cfg { float lo; float hi; unsigned char flag; };
extern "C" {
V cNode_GetLoc(PNode* node);
float cNodePickerParameters_Evaluate(Cfg* c, PNode* node, int idx, V* from, V* to);
}

static inline int IsZero(const V* v)
{
    int k, fl; unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Unit(V* p) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void Normalize(V* v, float* len) {
    int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%1); qmfc2.ni %0, $vf4; sw %0, 0x0(%2)" : "=&r"(t) : "r"(v), "r"(len) : "memory");
}
static inline float Length(V* a)
{
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory");
    return r;
}
static inline float Dot(V* a, V* b)
{
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory");
    return r;
}
float cNodePickerParameters_Evaluate(Cfg* c, PNode* node, int idx, V* from, V* to)
{
    float len = 0.0f;
    V d1 = *from - cNode_GetLoc(node);
    V d2 = cNode_GetLoc(node) - *to;
    V d3 = *from - *to;
    float dot = 0.0f;
    unsigned char z3 = 1;
    if (!IsZero(&d3)) {
        Unit(&d3);
        z3 = 0;
    }
    if (!IsZero(&d2)) {
        Normalize(&d2, &len);
        if (!z3) dot = Dot(&d3, &d2);
    }
    if (dot < -0.2588f) return 10000.0f;
    float dist = Length(&d1);
    float score;
    if (!(c->hi <= 0.0f)) score = dist + dist;
    else score = -0.25f * dist - len;
    if (len < c->lo || !(len <= c->hi)) score += 500.0f;
    if (c->flag && idx < 0) score += 1000.0f;
    return score;
}

