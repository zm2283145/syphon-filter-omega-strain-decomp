#include "types.h"

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

typedef struct { char pad[0x1C]; int size; char pad2[4]; int a; int b; } cNetQuickChatMsg;

/* cNetQuickChatMsg virtual 4: writes two 32-bit values and sets the message size to 0x40. */
void cNetQuickChatMsg_v04(cNetQuickChatMsg* self)
{
    write32(self->a);
    write32(self->b);
    self->size = 0x40;
}
