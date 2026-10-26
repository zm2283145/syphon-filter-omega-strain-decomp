#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { char pad[0x10]; unsigned int flags; int unk14; int unk18; } Obj;

/* Clears bit 0 of the flags and resets the field at +0x18. */
void _sceRpcFreePacket_void_2(Obj* obj)
{
    obj->unk18 = 0;
    obj->flags &= ~1;
}
