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

typedef struct { char pad[0x24]; float time; int id; } cNetLocalTimerMsg;

/* cNetLocalTimerMsg virtual 4: writes the time (raw float bits) and the id little-endian. */
void cNetLocalTimerMsg_v04(cNetLocalTimerMsg* self)
{
    writeFloat(self->time);
    write32(self->id);
}
