#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cXform_Rotate_cMatrixR(V4* a, V4* b) {
    char* pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf8, 0x0(pv1)
        lqc2 vf9, 0x10(pv1)
        lqc2 vf10, 0x20(pv1)
        lqc2 vf11, 0x30(pv1)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(pv1)
        sqc2 vf9, 0x10(pv1)
        sqc2 vf10, 0x20(pv1)
        sqc2 vf11, 0x30(pv1)
    }
}
