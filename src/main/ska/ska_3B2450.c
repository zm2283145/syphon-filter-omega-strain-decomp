/*
 * main/ska: range (3 files, 003B2450-003B24A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003B2450 */
#pragma push /* merge_units */
int func_003B2450(int a0) {
    int v0, v1;
    float f0, f1;
    int cond, fcc;

    f1 = *(float*)((char*)a0 + 12);
    v1 = 0x3f800000;
    f0 = 1.0f;
    fcc = f0 == f1;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003B2470;
    v0 = 0;
L003B2470:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2450 */

/* merge_units: begin func_003B2480 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* func_003B2480(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2480 */

/* merge_units: begin func_003B24A0 */
#pragma push /* merge_units */
void Quat_LerpWeighted(V4* a, V4* b, V4* c, V4* d, V4* e) {
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(d)
        lqc2 vf3, 0x0(e)
        vmulax.xyzw ACC, vf2, vf3x
        vmaddy.xyzw vf4, vf1, vf3y
        sqc2 vf4, 0x0(b)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B24A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B24A0 */
