/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00310D00(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 5;
    if (cond) goto L00310D14;
    v1 = *(int*)(char*)(a0 + 4);
    v0 = 0;
    *(int*)(char*)a1 = v1;
L00310D14:;
    goto ret;
ret:
    return v0;
}

int func_00310D20(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 5;
    if (cond) goto L00310D34;
    v1 = *(int*)(char*)(a0 + 528);
    v0 = 0;
    *(int*)(char*)a1 = v1;
L00310D34:;
    goto ret;
ret:
    return v0;
}
