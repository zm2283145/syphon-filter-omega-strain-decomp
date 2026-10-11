#include "types.h"
#include "vu_byval.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* v is a by-value V4 (the ABI passes its address) */
V4 func_001CF3A0(V4* vp, void* m) {
    VU_BYVAL(V4, vp, p)
    asm {
        lqc2 vf8, 0x0(p)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(p)
    }
    return *p;
}
#pragma pop