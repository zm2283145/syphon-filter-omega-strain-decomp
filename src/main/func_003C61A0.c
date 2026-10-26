#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
unsigned char cCollisionModel_Data_TestBox(void* unused, V4* a) {
    V4* b = a + 1;
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vcallmsr vi27
        cfc2.i r, vi1
        .set reorder
    }
    return r;
}