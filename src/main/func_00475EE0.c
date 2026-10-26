#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* Ladder_RungTarget: the root position snapped to the rung pitch. The climb distance is rounded to
 * a whole number of rung pairs and clamped to the ladder's travel; when i == 0 the travel limits
 * themselves are snapped inward to the pitch. Without a valid rung it returns the root position.
 * Types follow Ladder_BlendToTarget (Ladder_BlendToTarget.c). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Rung { char pad[0x980]; V base; float f990; float f994; float f998; };
struct Ladder { char pad[0x3298]; void* root; char pad2[0x3310 - 0x329C]; Rung* rung; };
extern float D_004A0410;
extern float D_004A0418;
extern "C" {
V Ladder_RungTarget(Ladder* l, int i);
void* Root_GetWorldPlacement(void*);
V* Placement_GetPosition(void*);
float func_00476230(Ladder* l, int i);
float Math_Floorf(float x);
float func_00121570(float x);
}
/* the accessor inlines (and the inner pos assignment) give retail's float register colouring */
static inline float Rung_Lo(Rung* r) { return r->f998 + D_004A0410; }
static inline float Rung_Hi(Rung* r) { return r->f990; }
static inline float Pitch() { return D_004A0418; }
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }

V Ladder_RungTarget(Ladder* l, int i)
{
    if (l->rung && Rung_Valid(l->rung)) {
        float pos = func_00476230(l, 0);
        pos = Math_Floorf(0.5f + (pos = pos / 2.0f));
        pos = pos * 2.0f;
        V base = l->rung->base;
        float z = base.z;
        float lo = Rung_Lo(l->rung) - z;
        float hi = Rung_Hi(l->rung) - z;
        if (!i) {
            lo = lo - 0.5f * Pitch();
            lo = lo / 2.0f;
            lo = func_00121570(lo);
            lo = lo * 2.0f;
            hi = hi + 0.5f * Pitch();
            hi = hi / 2.0f;
            hi = Math_Floorf(hi);
            hi = hi * 2.0f;
        }
        if (lo <= hi) {
            if (pos < lo)
                pos = lo;
            else if (pos > hi)
                pos = hi;
        }
        V r = base;
        r.z += pos;
        return r;
    }
    return *Placement_GetPosition(Root_GetWorldPlacement(l->root));
}
