#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_1400;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
P_1400* cQuatVec_InvertAssumingUnitQuat(P_1400* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    { V4* v; v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma pop