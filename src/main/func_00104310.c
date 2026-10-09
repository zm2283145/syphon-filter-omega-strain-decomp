/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00103BE8(int);

int func_00104310(int a0, int a1) {
    int v0;
    int cond;

    v0 = 0 + 1;
    cond = a1 != v0;
    if (cond) goto L00104330;
    v0 = *(int*)(char*)a0;
    v0 = (unsigned int)v0 >> 8;
    v0 = v0 & 1;
    goto L0010433C;
L00104330:;
    v0 = func_00103BE8(a0);
    v0 = 0;
L0010433C:;
    goto ret;
ret:
    return v0;
}
