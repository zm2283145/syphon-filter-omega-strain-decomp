#include "types.h"
int func_001ED7B0(int* a, int* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}