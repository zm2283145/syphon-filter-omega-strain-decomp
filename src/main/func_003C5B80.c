#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
unsigned char func_003C5B80(void* unused, V4* a, V4* b, V4* c) {
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        lqc2 vf3, 0(c)
        vcallmsr vi27
        cfc2.i r, vi1
        .set reorder
    }
    return r;
}