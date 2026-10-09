/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00356B30(int, int, int, int, int);

int func_0034FA40(int a0, int a1, int a2, int a3) {
    int t0, v0, v1;
    int cond;

    v1 = a2 & 65535;
    v0 = 0 + 12288;
    cond = v1 != v0;
    if (cond) goto L0034FA60;
    *(int*)(char*)(a0 + 128) = a3;
    v0 = 0 + 1;
    goto L0034FA68;
L0034FA60:;
    v0 = func_00356B30(a0, a1, a2, a3, t0);
L0034FA68:;
    goto ret;
ret:
    return v0;
}
