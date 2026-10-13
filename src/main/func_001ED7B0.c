#include "types.h"
int HumanColQueryMask_Equals(int* a, int* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}