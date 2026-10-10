#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { char pad[0x8C]; int flag; long value; } Packet; /* long is 64-bit on EE-GCC */
typedef struct { char pad[0x40]; Packet* packet; } Ctx;

/* Stores a 64-bit value into the context's packet and marks it valid; always returns 1. */
int func_0010B528(Ctx* ctx, long value)
{
    Packet* p = ctx->packet;
    p->flag = 1;
    p->value = value;
    return 1;
}
