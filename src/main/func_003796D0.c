#include "types.h"

typedef struct { char pad[0x50]; unsigned long long bits; } Rec50;
typedef struct { char pad[8]; Rec50** items; } RecTable;

/* Returns the low 14 bits of the 64-bit field of item i (as a 64-bit value). */
long long func_003796D0(RecTable* t, int i)
{
    long long bits = t->items[i]->bits;
    return (int)(bits & 0x3FFF);
}
