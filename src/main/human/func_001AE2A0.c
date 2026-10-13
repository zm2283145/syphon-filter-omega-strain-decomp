#include "types.h"
void BitArray_Assign(unsigned int* bits, int idx, int set)
{
    if (set) {
        bits[idx / 32] |= 1 << (idx & 31);
    } else {
        bits[idx / 32] &= ~(1 << (idx & 31));
    }
}