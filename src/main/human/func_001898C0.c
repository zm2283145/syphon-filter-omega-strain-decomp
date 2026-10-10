#include "types.h"
/* Test bit `index` of an int bit array. */
int AnimPriority_Helper3(int* bits, int index)
{
    return ((bits[index / 32] >> (index & 0x1F)) & 1) != 0;
}
