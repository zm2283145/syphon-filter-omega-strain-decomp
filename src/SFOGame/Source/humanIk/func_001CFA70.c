#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cQuaternion_Conjugate(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(a)
    }
    return a;
}
