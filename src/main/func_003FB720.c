/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003FB750(int);

int func_003FB720(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 12);
    v0 = 0x7f000000;
    v0 = v1 & v0;
    v0 = (unsigned int)v0 >> 24;
    a0 = v0 + -1;
    cond = a0 >= 0;
    if (cond) goto L003FB740;
    a0 = 0;
L003FB740:;
    v0 = func_003FB750(a0);
    goto ret;
ret:
    return v0;
}
