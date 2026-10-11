#include "types.h"
typedef struct { char pad[0x48]; int base; int size; char pad2[8]; int off; } T6940;
void func_003F6940(int* p1, int* n1, int* p2, int* n2, T6940* t, int x)
{
    int r;
    int d;
    int size = t->size;
    int off = t->off;
    r = (x + size - off - 0x400) % size;
    d = x - off;
    if (d >= 0 && d < 0x400) {
        *p1 = t->base;
        *n1 = 0;
        *p2 = t->base;
        *n2 = 0;
        return;
    }
    r = (r / 1024) * 1024;
    if (!(size - off < r)) {
        *p1 = t->base + off;
        *n1 = r;
        *p2 = 0;
        *n2 = 0;
    } else {
        *p1 = t->base + off;
        *n1 = t->size - t->off;
        *p2 = t->base;
        *n2 = r - (t->size - t->off);
    }
}