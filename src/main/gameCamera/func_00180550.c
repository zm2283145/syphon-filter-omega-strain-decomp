#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_00180550(V4* a) {
    char* pv1 = (char*)a + 0x20;
    asm {
        lqc2 vf1, 0x0(pv1)
        vmul.xyzw vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddaz.w ACC, vf0, vf2z
        vmaddw.w vf3, vf0, vf2w
        vrsqrt Q, vf0w, vf3w
        vwaitq 
        vmulq.xyzw vf4, vf1, Q
        sqc2 vf4, 0x0(pv1)
    }
}
