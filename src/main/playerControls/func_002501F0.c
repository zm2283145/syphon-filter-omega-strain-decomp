#include "types.h"
typedef struct { int head; int bits[1]; } SelectorT;
#pragma optimization_level 3
SelectorT* Selector_Copy(SelectorT* d, const SelectorT* s)
{
    int i;
    d->head = s->head;
    for (i = 0; i < 2; i++) {
        int w = i / 32;
        int b = i & 31;
        if ((s->bits[w] >> b) & 1)
            d->bits[w] |= 1 << b;
        else
            d->bits[w] &= ~(1 << b);
    }
    return d;
}