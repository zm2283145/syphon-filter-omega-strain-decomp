#include "types.h"
typedef struct { __int128 r[4]; } M_D1B0;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D1B0 m[8]; } S_D1B0;
void XLib_AppendView(S_D1B0* s, M_D1B0* b) {
    M_D1B0* t = &s->m[s->top];
    asm {
        lqc2 vf4, 0x0(t)
        lqc2 vf5, 0x10(t)
        lqc2 vf6, 0x20(t)
        lqc2 vf7, 0x30(t)
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
        sqc2 vf12, 0x0(t)
        sqc2 vf13, 0x10(t)
        sqc2 vf14, 0x20(t)
        sqc2 vf15, 0x30(t)
    }
    s->flag = 1;
}