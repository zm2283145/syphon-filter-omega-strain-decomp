#include "types.h"
typedef struct G6Big { struct G6Big* next; int k, maxwds, sign, wds; unsigned int x[1]; } G6Big;
int func_00126B70(G6Big* a, G6Big* b)
{
    unsigned int *xa, *xa0, *xb, *xb0;
    int i, j;
    i = a->wds;
    j = b->wds;
    if (i -= j) return i;
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb)
            return *xa < *xb ? -1 : 1;
        if (xa <= xa0)
            break;
    }
    return 0;
}