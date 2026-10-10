#include "types.h"

typedef struct { char pad[0x1C]; unsigned int mask; } BitObj;

/* Returns 1 if bit n of the mask at +0x1C is set. */
int func_001909B0(BitObj* self, int n)
{
    return (self->mask & (1 << n)) != 0;
}
