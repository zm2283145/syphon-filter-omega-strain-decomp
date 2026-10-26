#include "types.h"
#pragma optimization_level 1
void std_swap_cSkaBlendSequenceItemPR_cSkaBlendSequenceItemPR(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
#pragma optimization_level reset
