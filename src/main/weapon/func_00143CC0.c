/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_00143B60(int);

void Global_ForceHolster(int a0) {
    int a1, v1;
    int cond;

    v1 = 0 + 6;
    a1 = *(unsigned char*)(char*)(a0 + 132);
    cond = a1 == v1;
    if (cond) goto L00143CE0;
    func_00143B60(a0);
L00143CE0:;
    goto ret;
ret:;
}
