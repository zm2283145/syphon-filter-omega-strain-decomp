#include "types.h"

typedef struct { char pad[0x24]; float time; char sub[1]; } cNetTimerMsg;

extern unsigned char* D_005061D0; /* network write cursor */
extern void func_00281C80(void* sub);

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* cNetTimerMsg virtual 4: writes the time (raw float bits) little-endian, then serializes the payload. */
void cNetTimerMsg_v04(cNetTimerMsg* self)
{
    float time = self->time;
    int value = *(int*)&time;
    write16((unsigned short)value);
    write16(value >> 16);
    func_00281C80(self->sub);
}
