#include "types.h"
#include "prio_bitset.h"
PB_DEFINE(PS_1EC340, 1)
#pragma opt_rotateloops off
PS_1EC340* func_001EC340(PS_1EC340* p, int v)
{
    int i;
    p->w[0] = 0;
    PS_1EC340_Set(p, 0);
    for (i = 1; i < 13; i++) PS_1EC340_Clr(p, i);
    PS_1EC340_Set(p, v);
    PB_FIND_TOP(PS_1EC340, p, i, 13)
    return p;
}
#pragma opt_rotateloops reset