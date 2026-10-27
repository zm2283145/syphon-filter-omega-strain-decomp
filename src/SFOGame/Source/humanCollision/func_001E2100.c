#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cXform_Transform(V4* a, V4* b) {
    char* pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        lqc2 vf8, 0x0(pv1)
        lqc2 vf9, 0x10(pv1)
        lqc2 vf10, 0x20(pv1)
        lqc2 vf11, 0x30(pv1)
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
        sqc2 vf12, 0x0(pv1)
        sqc2 vf13, 0x10(pv1)
        sqc2 vf14, 0x20(pv1)
        sqc2 vf15, 0x30(pv1)
    }
}
