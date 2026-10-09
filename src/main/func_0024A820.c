/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0024A820(int a0) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 37);
    v0 = (unsigned int)0 < (unsigned int)v0;
    v0 = v0 ^ 1;
    cond = v0 == 0;
    if (cond) goto L0024A83C;
    v0 = *(unsigned char*)(char*)(a0 + 36);
    v0 = (unsigned int)0 < (unsigned int)v0;
L0024A83C:;
    goto ret;
ret:
    return v0;
}
