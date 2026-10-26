#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* ActorPhys_GatherBounds: world-space box swept by the actor's collision
 * cylinder this frame: radius (2, or 3 while carrying), height (8, larger
 * when crouched/prone per the posture flags, 14 for type 9) and floor depth,
 * grown by 1 unit, unioned with its copy moved by the frame's motion, then
 * placed at the root's world position. */
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V lo, hi; Box() {} Box& operator=(const Box& o) { const Box* s = &o; Box* d = this; __int128 a, b; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); sq %1, 0x10(%3)" : "=&r"(a), "=r"(b) : "r"(s), "r"(d) : "memory"); return *this; } };
struct Owner { char pad[0xB0]; char coll[4]; };
/* 9 per-posture state slots of 160 bytes; [1] deep, [3] prone, [4] swim */
struct Slot { unsigned char on; char pad[159]; };
struct Phys {
    char pad0[0xC]; Owner* owner; char pad10[0x20 - 0x10]; int type; char pad24[0x2F0 - 0x24];
    V pos; V prev; char pad310[0x3D3 - 0x310]; unsigned char crouch;
    char pad3D4[0x3E0 - 0x3D4]; Slot st[9];
};
extern "C" {
extern char D_004A03C8[];
extern float D_004A0358;
extern float D_004A0400;
extern float D_004A0408;
void* RootCollection_FindByKey(void* coll, void* key);
void* Root_GetWorldPlacement(void* r);
V* Placement_GetPosition(void* p);
void cBox_ctor_cBoxR(Box* d, Box* s);
void Box_Union(Box* a, Box* b);
void ActorPhys_GatherBounds(Phys* self, Box* out);
}
static inline void AddXYZ(V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory"); }
static inline void SubV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void UnionInto(Box* o, Box* a, Box* b) { Box r; cBox_ctor_cBoxR(&r, a); Box_Union(&r, b); cBox_ctor_cBoxR(o, &r); }
static inline V operator-(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }

void ActorPhys_GatherBounds(Phys* self, Box* out)
{
    float pad = 1.0f; float height = 8.0f; float floor = -3.5f; float radius = 2.0f;
    int i;
    if (self->st[4].on)
        height = D_004A0408;
    else if (self->st[3].on)
        height = D_004A0400;
    else if (self->crouch)
        height += D_004A0358;
    if (self->st[1].on)
        floor = -8.0f;
    if (self->type == 9) {
        height = 14.0f;
        floor = -8.0f;
    }
    for (i = 0; i < 9; i++) {
        if (self->st[i].on) {
            radius = 3.0f;
            break;
        }
    }
    {
        V pos = *Placement_GetPosition(Root_GetWorldPlacement(RootCollection_FindByKey(self->owner->coll, D_004A03C8)));
        V d = self->pos - self->prev;
        V lo, hi;
        lo.x = -radius - pad; lo.y = -radius - pad; lo.z = floor - pad; lo.w = 1.0f;
        hi.x = radius + pad; hi.y = radius + pad; hi.z = height + pad; hi.w = 1.0f;
        Box b0; b0.lo = lo; b0.hi = hi;
        Box b1; b1.lo = b0.lo; b1.hi = b0.hi;
        Box o2;
        AddXYZ(&b1.lo, &d);
        AddXYZ(&b1.hi, &d);
        UnionInto(&o2, &b0, &b1);
        { Box* p = &o2; *out = o2; } /* p: retail keeps a dead sp+112 address here */
        AddXYZ(&out->lo, &pos);
        AddXYZ(&out->hi, &pos);
    }
}
