/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003AE020(int a0, float f12) {
    int at, v1;
    int cond;

    v1 = *(int*)(char*)a0;
    at = (unsigned int)v1 < (unsigned int)4;
    cond = at == 0;
    if (cond) goto L003AE048;
    v1 = v1 << 2;
    v1 = v1 + a0;
    *(float*)(char*)(v1 + 4) = f12;
    v1 = *(int*)(char*)a0;
    v1 = v1 + 1;
    *(int*)(char*)a0 = v1;
L003AE048:;
    goto ret;
ret:;
}
