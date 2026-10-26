#include "types.h"

/* compiler: ee-gcc -O2 (check.py --gcc) */

typedef struct { char pad[0x10]; unsigned int flags; char pad2[4]; int unk18; } FlagObj;

/* Clears bit 0 of the flags at +0x10 and zeroes +0x18. */
void _sceRpcFreePacket_void(FlagObj* self)
{
    self->unk18 = 0;
    self->flags &= ~1;
}
