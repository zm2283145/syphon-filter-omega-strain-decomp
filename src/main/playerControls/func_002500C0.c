#include "types.h"
typedef struct { int top; int bits[1]; } PrioSet_e8;
static inline unsigned char PrioSet_e8_Test(PrioSet_e8* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void PrioritySet_Set(PrioSet_e8* p, int bit)
{
    int i;
    p->bits[bit / 32] |= 1 << (bit & 31);
    for (i = 11; i >= 0 && !PrioSet_e8_Test(p, i); i--) {
    }
    if (!PrioSet_e8_Test(p, i)) {
        p->top = -1;
    } else {
        p->top = i;
    }
}