/*
 * lib/libkernl: 2 files, 001152B8-001152D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001152B8 */
#include "types.h"
extern int _sceSifLoadModule(int a, int b, int c, void* sp, int e);
/* Calls _sceSifLoadModule with a stack scratch buffer and a zero flag. */
int sceSifLoadModule(int a, int b, int c)
{
    int buf[4];
    return _sceSifLoadModule(a, b, c, buf, 0);
}
/* merge_units: end func_001152B8 */

/* merge_units: begin func_001152D8 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int _sceSifLoadModule(int, int, int, int, int);
#endif /* merge_units */
#define _sceSifLoadModule(a0, a1, a2, a3, a4) (_sceSifLoadModule((a0), (a1), (a2), (void *)(a3), (a4))) /* merge_units */


int sceSifLoadStartModule(int a0, int a1, int a2, int a3) {
    int tmp0;

    tmp0 = _sceSifLoadModule(a0, a1, a2, a3, 0);
    return tmp0;
}
#undef _sceSifLoadModule /* merge_units */
/* merge_units: end func_001152D8 */
