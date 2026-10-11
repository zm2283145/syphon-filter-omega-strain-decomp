#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7D80;
static inline V4_7D80 QMul_(V4_7D80* a, V4_7D80* b) {
    V4_7D80 r; V4_7D80* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4_7D80* func_001A7D80(V4_7D80* self, V4_7D80* o) {
    V4_7D80 t; V4_7D80* tp; t = QMul_(self, o); tp = &t; *self = *tp;
    return self;
}
#pragma pop