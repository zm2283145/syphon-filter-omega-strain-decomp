#include "types.h"
#include "pp_quad_copy.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void NiEvent_MulParentMatrix(PPMtx* out, PPMtx* a, PPMtx* b) {
    PPMtx t;
    __int128 qa; __int128 qb; PPMtx* s; PPMtx* p; p = &t;
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
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
        sqc2 vf12, 0x0(p)
        sqc2 vf13, 0x10(p)
        sqc2 vf14, 0x20(p)
        sqc2 vf15, 0x30(p)
    }
    s = &t;
    asm {
 .set noreorder
 lq qa, 0x0(s)
 lq qb, 0x10(s)
 sq qa, 0x0(out)
 lq qa, 0x20(s)
 sq qb, 0x10(out)
 lq qb, 0x30(s)
 sq qa, 0x20(out)
 sq qb, 0x30(out)
 .set reorder
 }
}
#pragma pop