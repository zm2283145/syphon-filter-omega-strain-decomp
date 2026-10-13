#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void Q5370(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q5370(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Rotate(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Rotated(V v) const { V* p = &v; Rotate(p); return *p; }
    void Translate(V v) { __asm__ volatile("lqc2 vf1, 0x30(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x30(%0)" : : "r"(this), "r"(&v) : "memory"); }
};
struct Muzzle { char pad[0x130]; V off; };
struct Weapon { char pad[0x2410]; Muzzle* muzzle[4]; };
extern "C" void ActorRender_GetAttachPoint(Weapon* a, M* out, int i);
extern "C" void Weapon_AddMuzzleOffset(Weapon* w, M* m, int i)
{
    ActorRender_GetAttachPoint(w, m, i);
    if (w->muzzle[i]) {
        m->Translate(m->Rotated(w->muzzle[i]->off));
    }
}


