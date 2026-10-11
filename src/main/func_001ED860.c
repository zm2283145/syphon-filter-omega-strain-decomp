#include "types.h"
int func_001ED860(const int* a, const int* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (*a != *b) return 0;
        b++; a++;
    }
    return 1;
}