#include "types.h"
typedef struct { char pad[8]; int* items; } Tbl35E0;
typedef struct { char pad[0x20C]; int slot; } Obj35E0;
extern Tbl35E0* D_004FFBE0;
int func_002D35E0(Obj35E0* o)
{
    int i = o->slot;
    int r = 0;
    if (i >= 0)
        r = D_004FFBE0->items[i];
    return r;
}