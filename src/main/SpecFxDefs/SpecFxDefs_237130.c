/*
 * main/SpecFxDefs: range (3 files, 00237130-002371F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00237130 */
#pragma push /* merge_units */
extern char D_004DBAE0[];
extern int func_003EBF10(int);
extern int func_003EC050(int, int);

int func_00237130(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L00237178;
    a1 = 0;
    v0 = (int)D_004DBAE0;
    *(int*)((char*)s1 + 20) = v0;
    v0 = func_003EC050(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L00237178;
    v0 = func_003EBF10(a0);
L00237178:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237130 */

/* merge_units: begin func_00237190 */
#pragma push /* merge_units */
extern char D_004DBB00[];

int func_00237190(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L002371D8;
    a1 = 0;
    v0 = (int)D_004DBB00;
    *(int*)((char*)s1 + 20) = v0;
    v0 = func_003EC050(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L002371D8;
    v0 = func_003EBF10(a0);
L002371D8:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237190 */

/* merge_units: begin func_002371F0 */
#pragma push /* merge_units */
extern char D_004DBB20[];

int func_002371F0(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L00237238;
    a1 = 0;
    v0 = (int)D_004DBB20;
    *(int*)((char*)s1 + 20) = v0;
    v0 = func_003EC050(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L00237238;
    v0 = func_003EBF10(a0);
L00237238:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002371F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002371F0 */
