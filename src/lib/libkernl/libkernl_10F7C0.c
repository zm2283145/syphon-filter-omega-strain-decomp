#include "types.h"

typedef struct { int used; int unk4; int unk8; } Slot12;

extern Slot12* D_004E2D64;
extern Slot12* D_004E2D6C;

/* compiler: ee-gcc -O2 (check.py --gcc) */

/* Frees a slot handle: negative handles index the second table (high bit masked). */
void func_0010F7C0(int handle)
{
    if (handle < 0)
        D_004E2D64[handle & 0x7FFFFFFF].used = 0;
    else
        D_004E2D6C[handle].used = 0;
}
