/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A2670(int);

int func_00394170(int a0) {
    int v0;
    int cond;

    a0 = *(int*)(char*)(a0 + 100);
    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L00394190;
    v0 = func_003A2670(a0);
    v0 = v0 & 255;
L00394190:;
    goto ret;
ret:
    return v0;
}
