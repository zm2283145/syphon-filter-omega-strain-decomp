#include "types.h"
#pragma peephole off
#pragma opt_common_subs off
#pragma opt_propagation off
Vec4 func_0014B1E0(Vec4* src)
{
    Vec4 t;
    Vec4* p;
    t = *src;
    p = &t;
    p->w = 1.0f;
    return *p;
}