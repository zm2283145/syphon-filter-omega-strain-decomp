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

typedef struct { char pad[0x24]; int a; int b; void* item; } cInventoryMsg;
extern void func_00282020(void* item);

/* cInventoryMsg virtual 4: serializes the item, then writes two 32-bit values. */
void cInventoryMsg_v04(cInventoryMsg* self)
{
    func_00282020(self->item);
    write32(self->a);
    write32(self->b);
}
