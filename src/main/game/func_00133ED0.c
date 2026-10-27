#pragma opt_common_subs off
#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "node_world_q4.h"
typedef MtxQ4 M_ED0;
struct Node_ED0 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; M_ED0 m; unsigned char dirty; char pad51[0x1D0 - 0x51]; };
struct Mdl_ED0 { char pad[0x14]; unsigned char hasSkel; char pad15[0xB]; Node_ED0* nodes; char pad24[4]; Node_ED0* root; };
#include "pp_quad_copy.h"
extern "C" M_ED0 cSkeleton_GetBoneToWorldMatrix(Mdl_ED0* self, int idx)
{
    if (self->hasSkel) {
        Node_ED0* r = self->root;
        if (r->dirty) r->Update();
        M_ED0* mm = &r->m;
        Node_ED0* n = &self->nodes[idx];
        if (n->dirty) n->Update();
        M_ED0 p; const M_ED0* fs; M_ED0* pp; M_ED0* fd; __int128 qa; __int128 qb; {
        fs = &n->m;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(qa) : "r"(fs));
        fd = &p;
        __asm__ volatile("lq %0, 0x10(%1)" : "=r"(qb) : "r"(fs));
        pp = &p;
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(qa), "r"(fd) : "memory");
        __asm__ volatile("lq %0, 0x20(%1)" : "=r"(qa) : "r"(fs));
        __asm__ volatile("sq %0, 0x10(%1)" : : "r"(qb), "r"(fd) : "memory");
        __asm__ volatile("lq %0, 0x30(%1)" : "=r"(qb) : "r"(fs));
        __asm__ volatile("sq %0, 0x20(%1)" : : "r"(qa), "r"(fd) : "memory");
        __asm__ volatile("sq %0, 0x30(%1)" : : "r"(qb), "r"(fd) : "memory"); }
        asm {
            lqc2 vf4, 0x0(mm)
            lqc2 vf5, 0x10(mm)
            lqc2 vf6, 0x20(mm)
            lqc2 vf7, 0x30(mm)
            lqc2 vf8, 0x0(pp)
            lqc2 vf9, 0x10(pp)
            lqc2 vf10, 0x20(pp)
            lqc2 vf11, 0x30(pp)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            vmulax.xyzw ACC, vf4, vf9x
            vmadday.xyzw ACC, vf5, vf9y
            vmaddaz.xyzw ACC, vf6, vf9z
            vmaddw.xyzw vf13, vf7, vf9w
            vmulax.xyzw ACC, vf4, vf10x
            vmadday.xyzw ACC, vf5, vf10y
            vmaddaz.xyzw ACC, vf6, vf10z
            vmaddw.xyzw vf14, vf7, vf10w
            vmulax.xyzw ACC, vf4, vf11x
            vmadday.xyzw ACC, vf5, vf11y
            vmaddaz.xyzw ACC, vf6, vf11z
            vmaddw.xyzw vf15, vf7, vf11w
            sqc2 vf12, 0x0(pp)
            sqc2 vf13, 0x10(pp)
            sqc2 vf14, 0x20(pp)
            sqc2 vf15, 0x30(pp)
        }
        return *pp;
    }
    Node_ED0* r = self->root;
    if (r->dirty) r->Update();
    { M_ED0* w = &r->m; return *w; }
}










