#include "types.h"
static unsigned char D_00493800[] = "abcdefghijklmnopqrstuvwxyz1234567890\nE\b\t -=[]?\\;'?,./";
static unsigned char D_00493840[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()\nE\b\t _+{}?|:\"?<>?";
unsigned char func_003D1580(unsigned char c, int flags)
{
    int v = c;
    if (v >= 0x42 || v < 4) return 0;
    if (v >= 0x3A && v < 0x42) return v + 0x46;
    return ((flags & 2) || (flags & 0x20)) ? D_00493840[v - 4] : D_00493800[v - 4];
}
