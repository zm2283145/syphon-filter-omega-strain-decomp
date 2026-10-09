/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0014D510(int, int, int);

int func_0014D4D0(int a0, int a1, float f12) {
    int tmp0;

    tmp0 = func_0014D510(a0, 0, a1);
    *(float*)((char*)a0 + 124) = f12;
    *(char*)((char*)a0 + 360) = 0;
    return tmp0;
}
