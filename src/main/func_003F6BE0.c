#include "types.h"
typedef struct { int state; unsigned char kind; char pad[3]; char buf[0x28]; int m30; int m34; int m38; int m3C; int m40; } T6BE0;
void func_003F6BE0(T6BE0* t, int* p1, int* n1, int* p2, int* n2)
{
    if (t->state == 0) {
        if (t->kind != 4) {
            *p1 = (int)(t->m30 + (int)t + 8);
            *n1 = 0x28 - t->m30;
            *p2 = t->m34;
            *n2 = t->m40;
        } else {
            *p1 = t->m34;
            *n1 = t->m40;
            *p2 = 0;
            *n2 = 0;
        }
    } else {
        int len;
        int size = t->m40;
        int pos;
        len = size - t->m3C;
        pos = t->m38;
        if (!(size - pos < len)) {
            *p1 = t->m34 + pos;
            *n1 = len;
            *p2 = 0;
            *n2 = 0;
        } else {
            *p1 = t->m34 + pos;
            *n1 = t->m40 - t->m38;
            *p2 = t->m34;
            *n2 = len - (t->m40 - t->m38);
        }
    }
}
