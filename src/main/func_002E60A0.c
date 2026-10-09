/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005202E8[];

int func_002E60A0(int a0) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 23;
    if (cond) goto L002E60B8;
    v0 = 0;
    v1 = (int)D_005202E8;
    *(int*)(char*)a0 = v1;
L002E60B8:;
    goto ret;
ret:
    return v0;
}
