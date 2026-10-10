#include "types.h"

extern unsigned char* D_005061D0; /* read cursor */

/* Reads a little-endian 16-bit value from the cursor. */
static inline short ReadShort(void) {
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads two 16-bit halves from the cursor and stores them as one 32-bit word. */
void Script_ReadU32(unsigned int* out) {
    unsigned short low = ReadShort();
    unsigned short high = ReadShort();
    *out = low + (high << 16);
}
