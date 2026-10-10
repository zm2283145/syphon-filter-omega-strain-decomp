#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x40]; int cur; int bits[54]; int x11C; int x120; } F6Bits;
static inline bool F6Test(F6Bits* s, int i) { return ((s->bits[i / 32] >> (i & 31)) & 1) ? true : false; }
extern "C" void func_0024B410(F6Bits* s)
{
    int i;
    s->bits[0] &= ~0x800;
    for (i = 11; i >= 0 && !F6Test(s, i); i--) {
    }
    if (!F6Test(s, i)) {
        s->cur = -1;
    } else {
        s->cur = i;
    }
    s->x11C = 0;
    s->x120 = 0;
}