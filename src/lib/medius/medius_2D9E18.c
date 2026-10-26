/*
 * lib/medius: 2 files, 002D9E18-002D9E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D9E18 */
#include "types.h"

extern int GridGetByChannel(int, int);

int GetGrid(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 100);
    return GridGetByChannel(tmp0, a1);
}
/* merge_units: end func_002D9E18 */

/* merge_units: begin func_002D9E30 */
extern int GridRemoveGrid(int);

int RemoveGrid(int a0, int a1) {
    int s0, v0;
    int cond;

    s0 = a1;
    cond = s0 == 0;
    if (cond) goto L002D9E60;
    v0 = *(int*)((char*)a0 + 100);
    cond = s0 != v0;
    if (cond) goto L002D9E58;
    *(int*)((char*)a0 + 100) = 0;
    goto L002D9E60;
L002D9E58:;
    a0 = s0;
    v0 = GridRemoveGrid(a0);
L002D9E60:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
/* merge_units: end func_002D9E30 */
