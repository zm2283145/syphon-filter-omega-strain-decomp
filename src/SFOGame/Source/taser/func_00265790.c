/* 00265790 cAirTaser::SmoothLine(float amt, bool decay) (taser.cc) */
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator*(float k) const { return Scaled(k); }
    V Scaled(float k) const { V r; ScaleV(&r, this, k); return r; }
} __attribute__((aligned(16)));

// VU0 macro-mode vector op (COP2), not expressible in C
static inline V operator+(const V& a, const V& b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
struct Seg { V p; char pad[0x30]; };
struct cArray { char pad0[4]; int count; Seg* data; char padC[4]; Seg& operator[](int i) { return data[i]; } int Count() { return count; } };
struct cAirTaser { char pad0[0x10]; cArray mPoints; void SmoothLine(float amt, bool decay); };

extern "C" {
extern float D_0048B1A8;
extern float D_0048B1B0;
void cAirTaser_SmoothLine(cAirTaser* self, bool decay, float amt);
}

void cAirTaser_SmoothLine(cAirTaser* self, bool decay, float amt)
{
    int cnt = self->mPoints.Count() - 1;
    if (decay) {
        cnt = (int)((float)cnt * D_0048B1A8);
    }
    for (int i = 1; i < cnt; i++) {
        V mid = (self->mPoints.data[i - 1].p + self->mPoints.data[i + 1].p) * 0.5f;
        float factor;
        if (decay) {
            factor = (float)(cnt - i) / (float)(cnt - 1);
        } else {
            factor = 1.0f;
        }
        factor *= D_0048B1B0;
        float adjustPct = amt * factor;
        self->mPoints[i].p.x = mid.x * adjustPct + (1.0f - adjustPct) * self->mPoints[i].p.x;
        self->mPoints[i].p.y = (1.0f - adjustPct) * self->mPoints[i].p.y + mid.y * adjustPct;
        self->mPoints[i].p.z = (1.0f - adjustPct) * self->mPoints[i].p.z + mid.z * adjustPct;
    }
}
