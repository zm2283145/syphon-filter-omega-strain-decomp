#include "types.h"

/* Sets bit n in the objective mask (ignores negative n). */
void Objective_SetMaskBit(void* self, unsigned int* mask, int n)
{
    if (n > -1)
        mask[n / 32] |= 1 << (n & 31);
}
