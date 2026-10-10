#include "types.h"

extern unsigned char* D_005061D0; /* read cursor */

/* Reads a little-endian 16-bit value from the cursor. */
static inline short ReadShort(void) {
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads a 32-bit float (as two 16-bit halves) from the cursor. */
float Script_ReadFloat(void) {
    unsigned int bits;
    unsigned short low = ReadShort();
    unsigned short high = ReadShort();
    bits = low + (high << 16);
    return *(float*)&bits;
}
