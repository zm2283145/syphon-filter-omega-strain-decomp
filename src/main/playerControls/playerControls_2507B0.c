/*
 * main/playerControls: range (2 files, 002507B0-002508A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002507B0 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002507B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002507B0 */

/* merge_units: begin func_002508A0 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002508A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002508A0 */
