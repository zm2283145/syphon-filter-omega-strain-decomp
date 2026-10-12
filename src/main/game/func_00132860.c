#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_2860;
struct Mdl_2860 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; V_2860 m[4]; unsigned char dirty; };
struct Ctx_2860 { char pad[0x2E78]; Mdl_2860* model; char pad2e7c[0x24]; V_2860 pos; };
/* anchor point (sibling of ModelCtx_GetAnchor): refresh the model if dirty, transform pos by its matrix (VU0) */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" V_2860 Actor_GetPosition(Ctx_2860* self)
{
    Mdl_2860* m = self->model;
    if (m->dirty) m->Update();
    V_2860 p;
    V_2860* mm;
    V_2860* pp;
    VCopyF(&p, &self->pos);
    mm = m->m;
    pp = &p;
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
#pragma pop
