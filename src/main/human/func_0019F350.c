#include "types.h"
#include "pp_quad_copy.h"
#include "vu0_ops.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_0019F350(PPMtx* out, PPMtx* in, PPMtx* m) {
    PPMtx t;
    PPMtx* ps = &t;
    PPMtx* pd = &t;
    PP_COPY4(pd, in)
    VU0_MulRows44(ps, m);
    PP_COPY4(out, ps)
}
#pragma pop