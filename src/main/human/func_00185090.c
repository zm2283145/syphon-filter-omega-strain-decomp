#include "types.h"

extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads a little-endian 32-bit float from the network read cursor. */
void NetRead_Float(float* out)
{
    int bits[1];
    unsigned short lo = read16();
    bits[0] = lo + ((unsigned short)read16() << 16);
    *out = *(float*)bits;
}
