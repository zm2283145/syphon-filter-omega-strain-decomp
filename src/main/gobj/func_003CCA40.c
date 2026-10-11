#include "types.h"
#include "vu0_ops.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0xA0]; V4 vA0; } C3_Y;
typedef struct { char pad[0x54]; C3_Y* p54; } C3_X;
typedef struct { char pad[0x5C]; C3_X* p5C; } C3_O;
C3_X* func_003CCA40(C3_O* o) {
    C3_X* x = o->p5C;
    if (x) {
        if (x->p54 && !VU0_IsZero4(&x->p54->vA0)) return x;
        return 0;
    }
    return 0;
}