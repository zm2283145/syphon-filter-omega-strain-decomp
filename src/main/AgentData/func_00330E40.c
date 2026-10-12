#include "types.h"
extern unsigned char* D_005061D0;
static inline short R16_330E40(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_330E40(void) { unsigned short lo = R16_330E40(); return lo + ((unsigned short)R16_330E40() << 16); }
typedef struct { char p0[8]; int f[31]; char p84[0xB70 - 0x84]; unsigned char done; } T330E40;
void func_00330E40(T330E40* t) {
    int i;
    i = 14; do { t->f[i] = R32_330E40(); i++; } while (i < 31);
    t->done = 1;
}
