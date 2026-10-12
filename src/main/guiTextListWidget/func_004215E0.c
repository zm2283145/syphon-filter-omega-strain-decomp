#include "types.h"
typedef struct { char p[0xC]; int id; char p10[4]; } E4215E0;
typedef struct { char p[0x94]; int count; E4215E0* items; } L4215E0;
#pragma push
#pragma opt_common_subs off
int func_004215E0(L4215E0* l, int id)
{
    int i;
    for (i = 0; i < l->count; i++) if (((E4215E0*)((char*)l->items + i * sizeof(E4215E0)))->id == id) return i;
    return -1;
}
#pragma pop
