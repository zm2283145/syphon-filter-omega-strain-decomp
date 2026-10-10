#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { char pad[0xA8]; unsigned long value; } State; /* long is 64-bit on EE-GCC */
extern State* D_00489738;

/* Stores a zero-extended 32-bit value into the 64-bit field +0xA8 of the global state. */
void func_00127DB8(unsigned int value)
{
    D_00489738->value = value;
}
