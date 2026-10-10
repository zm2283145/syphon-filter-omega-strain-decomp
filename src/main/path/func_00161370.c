#include "types.h"
typedef struct { char pad[0x60]; unsigned char lo:4; unsigned char a:1; unsigned char b:1; } PfD4;
void func_00161370(PfD4* p, int v)
{
    if (p->b != (unsigned char)v) {
        p->a = v;
        p->b = v;
    } else {
        p->a = 0;
    }
}