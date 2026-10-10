#include "types.h"

typedef struct { char pad[0x24]; int player; int reason; } cNetKickMsg;

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

/* cNetKickMsg virtual 4: writes the player and reason as 32-bit little-endian values. */
void cNetKickMsg_v04(cNetKickMsg* self)
{
    write32(self->player);
    write32(self->reason);
}
