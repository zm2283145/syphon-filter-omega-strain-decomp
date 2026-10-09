/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0026C3B0(int);
extern int func_00272AC0(int);

void func_0026C7E0(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v1 = *(int*)(char*)(a0 + 36);
    cond = v1 == 0;
    if (cond) goto L0026C818;
    v0 = func_00272AC0(a0);
    cond = v0 != 0;
    a0 = s0;
    if (cond) goto L0026C818;
    v0 = func_0026C3B0(a0);
L0026C818:;
    goto ret;
ret:;
}
