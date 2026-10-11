#include "types.h"
typedef struct { char pad[0x14C]; unsigned char a14C; char pad2[0x13]; int* a160; } S36D380;
int func_0036D380(S36D380* o, int k)
{
    if (!o->a14C) return 0;
    return o->a160[k + 1] - o->a160[k];
}