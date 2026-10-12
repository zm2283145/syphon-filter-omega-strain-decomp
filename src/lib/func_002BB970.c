#include "types.h"
typedef struct { unsigned char b[16]; } K2BB970;
typedef struct { K2BB970 k; unsigned char pad[12]; } E2BB970;
extern E2BB970 D_00518A10[];
int func_002BB970(int i, K2BB970* k)
{
    D_00518A10[i].k = *k;
    return 1;
}