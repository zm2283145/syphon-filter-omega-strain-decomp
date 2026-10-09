/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00307128(int, int);

int func_00303080(int a0) {
    int a1, v0, v1;
    int cond;

    v0 = 0 + 2;
    cond = a0 == 0;
    if (cond) goto L003030A4;
    a0 = *(int*)((char*)a0 + 384);
    v0 = func_00307128(a0, a1);
    v1 = 0 + 7;
    if (v0 == 0) v1 = 0;
    v0 = v1;
L003030A4:;
    goto ret;
ret:
    return v0;
}
