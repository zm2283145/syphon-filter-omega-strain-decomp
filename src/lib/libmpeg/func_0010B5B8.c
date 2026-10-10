#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { char pad[0x108]; unsigned long data; int valid; } Packet;
typedef struct { char pad[0x40]; Packet* packet; } Ctx;

/* Stores a 64-bit value into the context packet, marks it valid and returns 1. */
int func_0010B5B8(Ctx* ctx, unsigned long data)
{
    Packet* p = ctx->packet;
    p->data = data;
    p->valid = 1;
    return 1;
}
