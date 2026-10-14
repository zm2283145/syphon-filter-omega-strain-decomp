/*
 * main/playerControls: range (3 files, 0024FFD0-002500C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0024FFD0 */
#pragma push /* merge_units */
float Math_MinF(float a, float b) {
    float r;
    asm { min.s r, a, b }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FFD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FFD0 */

/* merge_units: begin func_0024FFE0 */
#pragma push /* merge_units */
typedef struct { int top; int bits[1]; } PrioSet_e8;
static inline unsigned char PrioSet_e8_Test(PrioSet_e8* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void PrioritySet_Clear(PrioSet_e8* p, int bit)
{
    int i;
    p->bits[bit / 32] &= ~(1 << (bit & 31));
    for (i = 11; i >= 0 && !PrioSet_e8_Test(p, i); i--) {
    }
    if (!PrioSet_e8_Test(p, i)) {
        p->top = -1;
    } else {
        p->top = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FFE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FFE0 */

/* merge_units: begin func_002500C0 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002500C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002500C0 */
