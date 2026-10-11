#include "types.h"
#include "vu0_ops.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 lo, hi; } Box;
static inline void BoxExt2_(void* box, void* q, int off) {
    char* hi = (char*)box + 0x10;
    char* p = (char*)q + off;
    asm {
        lqc2 vf1, 0(box)
        lqc2 vf2, 0(hi)
        lqc2 vf3, 0(p)
        vmini.xyz vf1, vf1, vf3
        vmax.xyz vf2, vf2, vf3
        sqc2 vf1, 0(box)
        sqc2 vf2, 0(hi)
    }
}
#pragma push
#pragma opt_common_subs off
Box* Box_Union(Box* a, Box* b) {
    if (b->lo.x <= b->hi.x) {
        VU0_BoxExtend(a, &b->lo);
        BoxExt2_(a, b, 0x10);
    }
    return a;
}
#pragma pop