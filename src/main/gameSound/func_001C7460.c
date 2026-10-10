#include "types.h"

extern unsigned char* D_005061D0; /* stream cursor */

static inline unsigned char ReadU8(void)
{
    return *D_005061D0++;
}

static inline short ReadS16(void)
{
    unsigned char lo = ReadU8();
    unsigned char hi = ReadU8();
    return lo + (hi << 8);
}

/* Reads a little-endian 32-bit value (two 16-bit halves) from the stream into *out. */
void Stream_ReadU32(int* out)
{
    unsigned short lo = ReadS16();
    unsigned short hi = ReadS16();
    *out = lo + (hi << 16);
}
