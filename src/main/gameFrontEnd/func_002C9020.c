#include "types.h"
static const unsigned int dat_0048C290[8] = { 0x1, 0x3, 0x5, 0x8, 0xB, 0x0, 0x0, 0x0 };
int func_002C9020(int x)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (x > ((int*)dat_0048C290)[i]) continue;
        return i + 1;
    }
    return 5;
}