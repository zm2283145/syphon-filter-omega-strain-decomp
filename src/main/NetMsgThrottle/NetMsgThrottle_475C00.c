#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" int AnimChannel_SetTarget(void* channel, int anim, int arg, float weight, float blend, float start);
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; }
} __attribute__((aligned(16)));
struct P4 : V {
    P4() {}
    P4& Set(const V& o) { P4* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(&o) : "memory"); return *this; }
    V& SetZ(float nz) { z = nz; return *this; }
};
struct Rung { char pad[0x990]; float f990; float f994; float f998; };
struct Anim { char pad[0x10]; char chan[1]; void Play() { Anim* a = this; AnimChannel_SetTarget(a->chan, 0x15, 0, 0.0f, 0.5f, 0.0f); } };
struct Ladder { char pad[0x2EC0]; Anim anim; char pad2ED4[0x3248 - 0x2ED1]; unsigned int flags; char pad324C[0x3294 - 0x324C]; void* root; char pad2[0x3310 - 0x3298]; Rung* rung; };
struct LChar { char pad[0x2EC0]; struct { char pad[0x10]; char chan[1]; } anim; };
extern float D_004A0410;
extern "C" void* Root_GetWorldPlacement(void*);
extern "C" V* Placement_GetPosition(void*);
extern "C" void func_001E1F10(void*, V*);
extern "C" int AnimChannel_SetTarget_(void* channel, int anim, int arg, float weight, float blend, float start);
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
extern "C" void Ladder_AlignTopBottom(Ladder* l, int top)
{
    V t1;
    V t2;
    P4 p1;
    P4 p2;
    void* root;
    V* pos;
    if (l->rung && Rung_Valid(l->rung)) {
        root = l->root;
        pos = Placement_GetPosition(Root_GetWorldPlacement(root));
        if (top) {
            float y = l->rung->f998 + D_004A0410;
            V& r = p1.Set(*pos).SetZ(y - 1.0f); t1 = r;
            func_001E1F10(root, &t1);
            l->flags |= 0x02000000;
        } else {
            Rung* r = l->rung;
            V& q = p2.Set(*pos).SetZ(r->f990); t2 = q;
            func_001E1F10(root, &t2);
            l->flags |= 0x04000000;
        }
        l->anim.Play();
    }
}

