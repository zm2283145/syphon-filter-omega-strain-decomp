#pragma cplusplus on
#include "types.h"
/* LosRegion_FindGlobal: nearest LOS region (by squared box distance) to a point.
   Iterator wraps its pointer in a nested struct so `it = b` is a block copy (lwc1/swc1);
   `it` declared first gets the top slot; dead `xx = &d` gives the duplicate addiu. */
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box { V mn; V mx; };
/* per-axis distance from p to the box (0 inside), via VU0 sign flags */
static inline V BoxDelta(const V* p, const Box* b)
{
    V r;
    int f1, f2, t;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%4); lqc2 $vf2, 0x0(%5); lqc2 $vf3, 0x0(%6); vsub.xyz $vf4, $vf2, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; vsub.xyz $vf5, $vf1, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %1, $vi17; vmulx.xyzw $vf6, $vf0, $vf0x; andi %2, %0, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf4, $vf0x; andi %2, %1, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf5, $vf0x; 1: andi %2, %0, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf4, $vf0x; andi %2, %1, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf5, $vf0x; 2: andi %2, %0, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf4, $vf0x; andi %2, %1, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf5, $vf0x; 3: sqc2 $vf6, 0x0(%3); .set reorder"
        : "=r"(f1), "=r"(f2), "=r"(t) : "r"(&r), "r"(p), "r"(&b->mn), "r"(&b->mx) : "memory");
    return r;
}
struct LosRegion {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box* GetBounds();
};
struct ItP { LosRegion** p; };
struct It {
    ItP q;
    bool operator==(const It& o) const { LosRegion** b = o.q.p; return q.p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
    It& operator++() { ++q.p; return *this; }
};
extern "C" {
extern void* D_004FFD48;
void* func_00224AB0(void* list);
void LosRegionArray_Begin(It* it, void* node);
void LosRegionArray_End(It* it, void* node);
}
extern "C" LosRegion* LosRegion_FindGlobal(const V* p)
{
    void* list = D_004FFD48;
    float best = 3.4028235e38f;
    LosRegion* found = 0;
    It it;
    It e;
    LosRegionArray_End(&e, func_00224AB0(list));
    It b;
    LosRegionArray_Begin(&b, func_00224AB0(list));
    for (it = b; it != e; ++it) {
        LosRegion* r = *it.q.p;
        V d = BoxDelta(p, r->GetBounds());
        void* xx = &d;
        float l = d.LenSq();
        if (l < best) {
            found = r;
            best = l;
            if (l == 0.0f)
                break;
        }
    }
    return found;
}
