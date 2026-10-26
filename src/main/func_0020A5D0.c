#include "types.h"
#pragma optimization_level 1

/* Swaps two ints. */
void std_swap_uintR_uintR(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
