#include "types.h"
extern unsigned char D_0049383C[];
extern unsigned char D_004937FC[];
unsigned char func_003D1580(unsigned char c, int flags)
{
    int v = c;
    if (v >= 0x42 || v < 4) return 0;
    if (v >= 0x3A && v < 0x42) return v + 0x46;
    return ((flags & 2) || (flags & 0x20)) ? D_0049383C[v] : D_004937FC[v];
}
