#include "types.h"
typedef struct { int top; int w[1]; } PS_2508A0;
static inline void BSet_2508A0(PS_2508A0* p, int i) { p->w[i / 32] |= 1 << (i & 31); }
static inline void BClr_2508A0(PS_2508A0* p, unsigned int i) { p->w[(int)i / 32] &= ~(1 << (i & 31)); }
static inline unsigned char BTest_2508A0(PS_2508A0* p, int i) { return ((p->w[i / 32] >> (i & 31)) & 1) != 0; }
#pragma opt_rotateloops off
PS_2508A0* PrioritySet_Init(PS_2508A0* p, int v)
{
    int i;
    p->w[0] = 0;
    BSet_2508A0(p, 0);
    for (i = 1; i < 12; i++) BClr_2508A0(p, i);
    BSet_2508A0(p, v);
    for (i = 11; i >= 0 && !BTest_2508A0(p, i); i--) ;
    if (!BTest_2508A0(p, i)) p->top = -1; else p->top = i;
    return p;
}
#pragma opt_rotateloops reset