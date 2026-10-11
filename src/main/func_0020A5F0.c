#include "types.h"
#pragma optimization_level 1
void func_0020A5F0(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
#pragma optimization_level reset
