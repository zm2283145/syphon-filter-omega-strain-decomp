/*
 * main/human: range (2 files, 001B8790-001B87E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001B8790 */
#pragma push /* merge_units */
extern int WeaponInv_Equip(int, int);
extern void WeaponInv_HolsterCurrent(int);

void func_001B8790(int a0, int a1, int a2) {
    int v0;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    cond = a0 == 0;
    if (cond) goto L001B87C8;
    cond = a1 == 0;
    if (cond) goto L001B87C0;
    WeaponInv_HolsterCurrent(a0);
    goto L001B87C8;
L001B87C0:;
    a1 = a2;
    v0 = WeaponInv_Equip(a0, a1);
L001B87C8:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B8790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B8790 */

/* merge_units: begin func_001B87E0 */
#pragma push /* merge_units */
void func_001B87E0(float* p, float* ang) {
    float a = *ang;
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    p[1] += a;
    p[2] += a;
    p[4] += a;
    p[6] += a;
    p[8] += a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B87E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B87E0 */
