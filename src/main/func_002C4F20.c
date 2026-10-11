#include "types.h"
extern unsigned char D_0048C0C0;
typedef struct { unsigned short max; unsigned short cur; } Ctr4F20;
unsigned char func_002C4F20(Ctr4F20* c)
{
    unsigned char r;
    if (D_0048C0C0) {
        c->cur = 0;
        D_0048C0C0 = 0;
    }
    if (c->cur < c->max) { c->cur++; r = 1; } else { r = 0; } return r;
}