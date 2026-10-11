#include "types.h"
typedef struct { int state; unsigned char kind; char pad[0x2B]; unsigned int m30; int m34; int m38; int m3C; int m40; int m44; int m48; int m4C; int m50; int m54; int m58; int m5C; } T6ED0;
extern int func_003A6C90(int size, int a, int b, int c, int d, int kind);
int func_003F6ED0(T6ED0* t, int a, int b, unsigned char kind)
{
    t->state = 0;
    t->kind = kind;
    t->m30 = 0;
    t->m34 = a;
    t->m38 = 0;
    t->m3C = 0;
    t->m40 = b;
    t->m44 = 0;
    t->m50 = 0;
    t->m58 = 0;
    t->m5C = 0;
    t->m58 = 0;
    t->m5C = 0;
    if (kind == 2)
        t->m4C = 0x6000;
    else if (kind == 3)
        t->m4C = 0x400;
    else
        t->m4C = 0xC000;
    t->m48 = func_003A6C90(t->m4C, 0x1000, 0x400, 0, 2, t->kind);
    return t->m48 >= 0;
}
