/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0041D8C0(int);

int func_00463940(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = func_0041D8C0(a0);
    cond = v0 == s0;
    if (cond) goto L00463968;
    v1 = *(unsigned short*)((char*)v0 + 20);
    v1 = v1 & 65533;
    *(short*)((char*)v0 + 20) = v1;
L00463968:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
