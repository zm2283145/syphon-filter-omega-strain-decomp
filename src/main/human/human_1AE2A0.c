/*
 * main/human: range (2 files, 001AE2A0-001AE320)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001AE2A0 */
#pragma push /* merge_units */
void BitArray_Assign(unsigned int* bits, int idx, int set)
{
    if (set) {
        bits[idx / 32] |= 1 << (idx & 31);
    } else {
        bits[idx / 32] &= ~(1 << (idx & 31));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE2A0 */

/* merge_units: begin func_001AE320 */
#pragma push /* merge_units */
void func_001AE320(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 80) = a1;
    if (cond) goto L001AE338;
    v1 = a1 + 12;
    goto L001AE348;
L001AE338:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001AE348:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 84) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE320 */
