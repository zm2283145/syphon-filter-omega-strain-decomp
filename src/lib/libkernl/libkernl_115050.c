/*
 * lib/libkernl: 2 files, 00115050-00115070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00115050 */
#include "types.h"
extern int func_00114A80(int a, int b, int c, void* sp);
/* Calls func_00114A80 passing the current stack pointer. */
int func_00115050(int a, int b, int c) { int dummy; return func_00114A80(a, b, c, &dummy); }
/* merge_units: end func_00115050 */

/* merge_units: begin func_00115070 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int func_00114A80(int, int, int, int);
#endif /* merge_units */
#define func_00114A80(a0, a1, a2, a3) (func_00114A80((a0), (a1), (a2), (void *)(a3))) /* merge_units */


int func_00115070(int a0, int a1, int a2, int a3) {
    int tmp0;

    tmp0 = func_00114A80(a0, a1, a2, a3);
    return tmp0;
}
#undef func_00114A80 /* merge_units */
/* merge_units: end func_00115070 */
