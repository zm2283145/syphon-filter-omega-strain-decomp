/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern void func_00242900(int);

void func_002261C0(int a0) {
    int s0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)(a0 + 172);
    cond = v1 == 0;
    s0 = a0;
    if (cond) goto L002261E8;
    a0 = *(int*)(char*)D_004FFC2C;
    func_00242900(a0);
    *(char*)(char*)(s0 + 172) = 0;
L002261E8:;
    goto ret;
ret:;
}
