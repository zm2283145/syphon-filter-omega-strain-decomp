#include "types.h"

typedef struct { char pad[0x24]; void* tank; int value; } cNetCreateTankMsg;

extern unsigned char* D_005061D0; /* network write cursor */
extern void func_00284750(void* tank);

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* cNetCreateTankMsg virtual 4: writes the 32-bit value little-endian, then serializes the tank. */
void cNetCreateTankMsg_v04(cNetCreateTankMsg* self)
{
    int value = self->value;
    write16((unsigned short)value);
    write16(value >> 16);
    func_00284750(self->tank);
}
