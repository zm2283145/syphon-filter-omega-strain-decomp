#include "types.h"
void NellyDemultiplex(float* src, float* a, float* b, int n)
{
    while (n-- > 0) {
        *a++ = *src++;
        *b++ = *src++;
    }
}