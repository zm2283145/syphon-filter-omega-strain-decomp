/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00436EA0(int, int);

void func_00436C50(int a0) {
    int a1, s0, v0, v1;
    int cond;

    a1 = *(int*)(char*)(a0 + 4);
    cond = a1 == 0;
    s0 = a0;
    if (cond) goto L00436C80;
    v0 = func_00436EA0(a0, a1);
    *(int*)(char*)s0 = 0;
    v1 = s0 + 4;
    *(int*)(char*)(s0 + 4) = 0;
    *(int*)(char*)(s0 + 12) = v1;
L00436C80:;
    goto ret;
ret:;
}
