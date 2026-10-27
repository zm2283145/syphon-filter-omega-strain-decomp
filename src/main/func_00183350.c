#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
float cVector_GetLength(V4* a) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq 
        vaddq.x vf4, vf0, Q
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
