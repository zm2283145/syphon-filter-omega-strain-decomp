#include "types.h"
typedef struct { int state; unsigned char kind; char pad[0x2B]; unsigned int m30; int m34; int m38; int m3C; int m40; int m44; } T6B00;
void func_003F6B00(T6B00* t, int n)
{
    if (t->state == 0) {
        if (t->kind != 4) {
            unsigned int k = 0x28 - t->m30;
            if (n < k)
                k = n;
            t->m30 += k;
            if (!(t->m30 < 0x28))
                t->state = 1;
            n -= k;
        } else {
            t->state = 1;
        }
    }
    if (t->kind == 3)
        t->m40 = (t->m40 / 256) * 256;
    t->m38 = (t->m38 + n) % t->m40;
    t->m3C += n;
    t->m44 += n;
}