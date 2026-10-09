/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00555070[];
extern int func_001294F8(int);
extern int func_003D9DA0(int, int);
extern int func_003E15B0(int, int, int, int);

int func_003D9D20(int a0, int a1) {
    return (*(int*)(char*)a0 + (a1 << 2));
}

void func_003D9D30(int a0, int a1) {
    int loc[1];
    int a2, a3, s0, s1, v0;
    int cond;

    s0 = a1;
    cond = s0 == 0;
    s1 = a0;
    if (cond) goto L003D9D80;
    a0 = s0;
    v0 = func_001294F8(a0);
    cond = v0 == 0;
    if (cond) goto L003D9D80;
    a1 = s0;
    a0 = (int)D_00555070;
    a2 = s1 + 8;
    a3 = (int)loc;
    *(int*)(char*)loc = 0;
    v0 = func_003E15B0(a0, a1, a2, a3);
    a1 = *(int*)(char*)loc;
    a0 = s1;
    v0 = func_003D9DA0(a0, a1);
L003D9D80:;
    goto ret;
ret:;
}
