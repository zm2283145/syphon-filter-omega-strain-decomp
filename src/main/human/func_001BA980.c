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


typedef struct { char pad[0x24]; unsigned char type; char pad25[3]; float x; float y; } cNetShockMsg;

/* cNetShockMsg virtual 4: writes the type byte and two floats (raw bits) little-endian. */
void cNetShockMsg_v04(cNetShockMsg* self)
{
    float y;
    float x;
    *D_005061D0++ = self->type;
    x = self->x;
    write32(*(int*)&x);
    y = self->y;
    write32(*(int*)&y);
}
