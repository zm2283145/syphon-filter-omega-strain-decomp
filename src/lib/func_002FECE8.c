/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002FECE8(int a0, int a1) {
    int v0;
    int cond;

    a0 = a0 & 65535;
    v0 = 0 + 2;
    cond = a1 == 0;
    a0 = a0 + 73;
    if (cond) goto L002FED00;
    *(short*)(char*)a1 = a0;
    v0 = 0;
L002FED00:;
    goto ret;
ret:
    return v0;
}
