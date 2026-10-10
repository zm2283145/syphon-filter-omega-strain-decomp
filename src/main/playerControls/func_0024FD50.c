#include "types.h"
typedef struct { char pad[0x3C]; int bits[1]; } F24FD50;
int func_0024FD50(F24FD50* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}