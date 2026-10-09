/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003071C0(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a1 == 0;
    v0 = 0 + 1;
    if (cond) goto L003071E0;
    *(int*)(char*)a1 = 0;
    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L003071E0;
    v1 = *(int*)((char*)a0 + 60);
    v0 = 0;
    *(int*)(char*)a1 = v1;
L003071E0:;
    goto ret;
ret:
    return v0;
}
