/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005716C0[];

int func_0025AC20(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)(a0 + 288);
    v0 = *(int*)(char*)(v0 + 316);
    cond = v0 == 0;
    if (cond) goto L0025AC38;
    v0 = v0 + 992;
    goto L0025AC40;
L0025AC38:;
    v0 = (int)D_005716C0;
L0025AC40:;
    goto ret;
ret:
    return v0;
}
