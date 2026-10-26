#include "types.h"

#pragma optimization_level 1
/* Swaps two ints (unit built at -O1). */
void std_swap_cSkaSwitchItemPR_cSkaSwitchItemPR(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
#pragma optimization_level reset
