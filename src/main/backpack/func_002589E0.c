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

static inline void writeFloat(float f)
{
    write32(*(int*)&f);
}

typedef struct { char pad[0x24]; int a; int b; void* crate; } cCrateInteractMsg;
extern void func_00282020(void* crate);

/* cCrateInteractMsg virtual 4: serializes the crate, then writes both values little-endian. */
void cCrateInteractMsg_v04(cCrateInteractMsg* self)
{
    func_00282020(self->crate);
    write32(self->a);
    write32(self->b);
}
