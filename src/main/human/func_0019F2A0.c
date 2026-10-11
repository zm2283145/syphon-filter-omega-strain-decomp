#include "types.h"
#include "pp_quad_copy.h"
#include "vu0_ops.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4* func_0019F2A0(V4* v, PPMtx* m)
{
    PPMtx t;
    PPMtx tmp;
    PPMtx* pm = &t;
    PPMtx* sw = &tmp;
    PPMtx* pd = &t;
    PPMtx* c1 = &tmp;
    float x;
    PP_COPY4(c1, m)
    x = sw->f[1]; sw->f[1] = sw->f[4]; sw->f[4] = x;
    x = sw->f[2]; sw->f[2] = sw->f[8]; sw->f[8] = x;
    x = sw->f[6]; sw->f[6] = sw->f[9]; sw->f[9] = x;
    PP_COPY4(pd, sw)
    VU0_ApplyMtx33(v, pm);
    return v;
}
#pragma pop