#include "types.h"
void func_0031AEA0(float* src, float* a, float* b, int n)
{
    while (n-- > 0) {
        *a++ = *src++;
        *b++ = *src++;
    }
}