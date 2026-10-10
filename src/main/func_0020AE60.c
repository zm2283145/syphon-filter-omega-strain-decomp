#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

/* Swaps two ints. */
void func_0020AE60(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#pragma pop
