#include "types.h"
typedef struct { char pad[0xBC]; int bits[8]; } S_BFB0;
unsigned char func_0014BFB0(S_BFB0* self, int i)
{
    unsigned char r = 1;
    if (i >= 0)
        r = ((self->bits[i / 32] >> (i & 31)) & 1) != 0;
    return r;
}