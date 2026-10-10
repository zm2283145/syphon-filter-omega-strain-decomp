#include "types.h"

/* Writes the bitwise complement of *src to *dst; returns 0. */
int func_001ED8A0(int* dst, int* src) {
    volatile int inverted;
    volatile int value;
    value = *src;
    inverted = ~value;
    *dst = inverted;
    return 0;
}
