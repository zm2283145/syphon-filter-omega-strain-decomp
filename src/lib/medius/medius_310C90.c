/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00310F88(int, int, int, int);

int func_00310C90(int a0, int a1, int a2, int a3) {
    int v0;
    int cond;

    a3 = a3 & 255;
    cond = a0 == 0;
    v0 = 0 + 5;
    if (cond) goto L00310CB0;
    a0 = *(int*)(char*)a0;
    v0 = func_00310F88(a0, a1, a2, a3);
    v0 = (unsigned int)0 < (unsigned int)v0;
L00310CB0:;
    goto ret;
ret:
    return v0;
}
