#include "types.h"

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* Writes a float to the network stream as its 32-bit pattern, little-endian. */
void func_001B99E0(float f)
{
    int bits = *(int*)&f;
    write16((unsigned short)bits);
    write16(bits >> 16);
}
