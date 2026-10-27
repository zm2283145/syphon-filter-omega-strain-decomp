#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Subtract(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
