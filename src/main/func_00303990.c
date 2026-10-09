/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00303990(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = (unsigned int)a1 < (unsigned int)257;
    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L003039AC;
    cond = v1 == 0;
    if (cond) goto L003039AC;
    *(int*)((char*)a0 + 392) = a1;
    v0 = 0;
L003039AC:;
    goto ret;
ret:
    return v0;
}
