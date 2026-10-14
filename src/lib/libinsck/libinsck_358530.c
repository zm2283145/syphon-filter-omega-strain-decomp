/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00357178(int);

int func_00358530(int a0) {
    int v0;
    int cond;

    cond = a0 != 0;
    if (cond) goto L00358544;
    v0 = 0 + -1;
    goto L0035854C;
L00358544:;
    a0 = a0 & 65535;
    v0 = func_00357178(a0);
L0035854C:;
    goto ret;
ret:
    return v0;
}

int func_00358558(int a0) {
    int tmp0;

    tmp0 = func_00357178((a0 & 65535));
    return tmp0;
}
