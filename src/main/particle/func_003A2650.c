#include "types.h"

typedef struct { char pad[0x30]; Q q; char pad2[0x28]; signed char value; } Obj;

/* Optionally copies the vector at +0x30 out and returns the byte at +0x68. */
#pragma peephole off
signed char func_003A2650(Obj* self, Q* out)
{
    if (out) {
        *out = self->q;
    }
    return self->value;
}
#pragma peephole reset
