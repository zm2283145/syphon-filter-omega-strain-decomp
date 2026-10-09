/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFBD0[];
extern int func_00170E20(int, int, int, int);

void func_00256180(int a0) {
    int a1, a2, a3, s0, v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 764);
    cond = v1 != 0;
    s0 = a0;
    if (cond) goto L002561C0;
    a1 = s0;
    a0 = *(int*)(char*)D_004FFBD0;
    a2 = 0;
    a3 = 0 + 1;
    v0 = func_00170E20(a0, a1, a2, a3);
    *(int*)(char*)(s0 + 764) = v0;
    a0 = *(int*)(char*)(s0 + 12);
    v1 = *(int*)(char*)(s0 + 764);
    *(int*)(char*)(v1 + 148) = a0;
L002561C0:;
    goto ret;
ret:;
}
