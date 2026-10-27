#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_910 { __int128 q; V_910() {} V_910(const V_910& o) { V_910* pd = this; const V_910* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } } };
static inline void VCp(V_910* pd, const V_910* ps) { asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
struct Node_910 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; V_910 m[4]; unsigned char dirty; char pad51[0x1D0 - 0x51]; };
struct Mdl_910 { char pad[0x14]; unsigned char hasSkel; char pad15[0xB]; Node_910* nodes; char pad24[4]; Node_910* root; };

extern "C" V_910 cSkeleton_GetBoneToWorldTranslation(Mdl_910* self, int idx)
{
    if (self->hasSkel) {
        Node_910* r = self->root;
        if (r->dirty) r->Update();
        V_910* mm = r->m;
        Node_910* n = &self->nodes[idx];
        if (n->dirty) n->Update();
        V_910 p; VCp(&p, &n->m[3]);
        V_910* pp = &p;
        asm {
            lqc2 vf8, 0x0(pp)
            lqc2 vf4, 0x0(mm)
            lqc2 vf5, 0x10(mm)
            lqc2 vf6, 0x20(mm)
            lqc2 vf7, 0x30(mm)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(pp)
        }
        return *pp;
    }
    Node_910* r = self->root;
    if (r->dirty) r->Update();
    return r->m[3];
}



