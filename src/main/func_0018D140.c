/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_001CAE10(int);

void func_0018D140(int a0) {
    int s0, v1;
    int cond;

    s0 = a0;
    a0 = *(int*)(char*)(a0 + 13076);
    cond = a0 == 0;
    if (cond) goto L0018D188;
    v1 = *(int*)(char*)(s0 + 12876);
    v1 = v1 >> 8;
    v1 = v1 & 1;
    cond = v1 == 0;
    if (cond) goto L0018D188;
    func_001CAE10(a0);
    a0 = *(int*)(char*)(s0 + 12876);
    v1 = 0 + -257;
    v1 = a0 & v1;
    *(int*)(char*)(s0 + 12876) = v1;
L0018D188:;
    goto ret;
ret:;
}
