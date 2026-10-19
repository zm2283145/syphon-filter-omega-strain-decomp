/*
 * lib/libgcc: 3 files, 00121B78-00121BC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121B78 */
#include "types.h"

extern char D_00489738[];
extern void Libc_Abort(void);
extern void func_001239D0(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

void __assert(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00489738;
    tmp1 = *(int*)((char*)tmp0 + 12);
    func_001239D0(tmp1, (int)"assertion \"%s\" failed: file \"%s\", line %d
", a2, a0, a1, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    Libc_Abort();
}
/* merge_units: end func_00121B78 */

/* merge_units: begin func_00121BB0 */
extern int strtod(int, int);

int atof(int a0) {
    return strtod(a0, 0);
}
/* merge_units: end func_00121BB0 */

/* merge_units: begin libgcc_121BC8 */
extern long strtol(const char* s, char** end, int base);
/* atoi: strtol(s, NULL, 10). */
int atoi(const char* s)
{
    return (int)strtol(s, 0, 10);
}
/* merge_units: end libgcc_121BC8 */
