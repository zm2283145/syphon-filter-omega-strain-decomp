#include "types.h"

extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

static inline int read32(void)
{
    unsigned short lo = read16();
    return lo + ((unsigned short)read16() << 16);
}

typedef struct { char pad[0x20]; unsigned char received; char pad21[3]; int a; int b; char item[1]; } cInventoryMsg;
extern void NetStream_ReadObject(void* item);
extern void Event_Send(cInventoryMsg* msg, void* target, int flags);

/* cInventoryMsg receive: reads the item and two 32-bit values, then dispatches to target. */
void cCrateInteractMsg_Apply(cInventoryMsg* self, void* target)
{
    NetStream_ReadObject(self->item);
    self->a = read32();
    self->b = read32();
    self->received = 1;
    Event_Send(self, target, 0);
}
