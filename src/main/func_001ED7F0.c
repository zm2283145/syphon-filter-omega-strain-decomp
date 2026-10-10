#include "types.h"

/* Stores the bitwise complement of *src into *dst (through stack temporaries); returns 0. */
int func_001ED7F0(int* dst, int* src)
{
    volatile int result;
    volatile int value;
    value = *src;
    result = ~value;
    *dst = result;
    return 0;
}
