#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4 func_001800A0(void) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        sqc2 vf0, 0x0(q1)
    }
    return l0;
}
