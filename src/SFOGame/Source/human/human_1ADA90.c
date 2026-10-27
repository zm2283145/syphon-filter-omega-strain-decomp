/*
 * main/human: range (2 files, 001ADA90-001ADAB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001ADA90 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Negate(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADA90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADA90 */

/* merge_units: begin func_001ADAB0 */
#pragma push /* merge_units */
void cSafePtr_cHuman_Set(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L001ADAC8;
    v1 = a1 + 12;
    goto L001ADAD8;
L001ADAC8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001ADAD8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADAB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADAB0 */
