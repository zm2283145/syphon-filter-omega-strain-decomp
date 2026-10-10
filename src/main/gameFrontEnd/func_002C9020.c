#include "types.h"
extern int D_0048C290[];
int func_002C9020(int x)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (x > D_0048C290[i]) continue;
        return i + 1;
    }
    return 5;
}