/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002FD968(int a0) {
    int v0;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L002FD978;
    *(int*)(char*)a0 = 0;
    v0 = 0;
L002FD978:;
    goto ret;
ret:
    return v0;
}
