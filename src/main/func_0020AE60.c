#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

/* Swaps two ints. */
void std_swap_cSkaTransBLENDPR_cSkaTransBLENDPR(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#pragma pop
