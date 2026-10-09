/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00301900(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L0030191C;
    cond = a1 == 0;
    if (cond) goto L0030191C;
    v1 = *(unsigned char*)(char*)a0;
    v0 = 0;
    *(char*)(char*)a1 = v1;
L0030191C:;
    goto ret;
ret:
    return v0;
}
