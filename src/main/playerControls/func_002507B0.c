#include "types.h"
#pragma cplusplus on

typedef struct { int sel; int bits[1]; } Sel250;
static inline bool Sel250_Test(Sel250* s, int i) { return ((s->bits[i / 32] >> (i & 31)) & 1) ? true : false; }
extern "C" Sel250* Selector_Init(Sel250* s, int n) {
    int i;
    s->bits[0] = 0;
    s->bits[0] |= 1;
    s->bits[0] &= ~2;
    s->bits[n / 32] |= 1 << (n & 31);
    i = 1;
    while (i >= 0 && !Sel250_Test(s, i)) i--;
    if (!Sel250_Test(s, i)) s->sel = -1;
    else s->sel = i;
    return s;
}