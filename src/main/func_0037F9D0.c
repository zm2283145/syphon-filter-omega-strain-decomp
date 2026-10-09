/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001004B0(int, int, int, int, int);
extern int func_003755C0(int);
extern int func_0037FE80(int);
extern int func_003BB2F0(int, int);
extern int func_003BB340(int);

int func_0037F9D0(int a0) {
    int a1, a2, a3, s0, s1, t0, v0;
    int cond;

    v0 = 0 + -1;
    s1 = a0;
    s0 = s1 + 496;
    *(int*)(char*)a0 = v0;
L0037F9F0:;
    a0 = s0;
    v0 = func_003755C0(a0);
    s0 = s0 + 272;
    v0 = s1 + 2672;
    cond = s0 != v0;
    if (cond) goto L0037F9F0;
    *(int*)(char*)(s1 + 4184) = 0;
    a0 = s1 + 4200;
    a1 = (int)func_003BB340;
    a2 = (int)func_003BB2F0;
    a3 = 0 + 20;
    t0 = 0 + 6;
    *(int*)(char*)(s1 + 4188) = 0;
    v0 = func_001004B0(a0, a1, a2, a3, t0);
    a0 = s1 + 4360;
    v0 = func_0037FE80(a0);
    v0 = s1;
    goto ret;
ret:
    return v0;
}
