#include "types.h"
#include "pp_quad_copy.h"
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00398D90(PPMtx* d, PPMtx* s)
{
    PP_TRANSPOSE33_COPY(d, s)
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma peephole reset