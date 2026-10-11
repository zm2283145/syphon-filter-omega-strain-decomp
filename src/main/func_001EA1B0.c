#include "types.h"
typedef struct { int head; int bits[1]; } B1EA1B0;
#pragma optimization_level 3
B1EA1B0* func_001EA1B0(B1EA1B0* d, const B1EA1B0* s)
{
    int i;
    d->head = s->head;
    for (i = 0; i < 13; i++) {
        int w = i / 32;
        int b = i & 31;
        if ((s->bits[w] >> b) & 1)
            d->bits[w] |= 1 << b;
        else
            d->bits[w] &= ~(1 << b);
    }
    return d;
}