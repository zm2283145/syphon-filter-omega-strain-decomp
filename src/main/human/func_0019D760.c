#include "types.h"

/* Returns 1 if bit n is set in the bit array. */
int BitArray_Test(int* bits, int n)
{
    return ((bits[n / 32] >> (n & 31)) & 1) != 0;
}
