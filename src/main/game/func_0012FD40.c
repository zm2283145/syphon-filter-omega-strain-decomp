/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0012FD40(int a0) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 100);
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 != 0;
    if (cond) goto L0012FD58;
    v0 = *(unsigned char*)(char*)(a0 + 98);
    v0 = (unsigned int)0 < (unsigned int)v0;
L0012FD58:;
    goto ret;
ret:
    return v0;
}
