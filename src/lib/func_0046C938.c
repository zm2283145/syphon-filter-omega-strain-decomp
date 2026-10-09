/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497CD0[];
extern char D_00497CFC[];

int func_0046C938(void) {
    return 38;
}

int func_0046C940(int a0, int a1, int a2, int a3) {
    int v0;
    int cond;

    v0 = *(int*)((char*)a3 + 24);
    cond = v0 != 0;
    if (cond) goto L0046C960;
    *(char*)(char*)D_00497CD0 = 0;
L0046C960:;
    v0 = *(int*)(char*)D_00497CFC;
    cond = v0 == 0;
    if (cond) goto L0046C978;
    v0 = ((int (*)(void))v0)();
L0046C978:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046C988(void) {
    return 166;
}
