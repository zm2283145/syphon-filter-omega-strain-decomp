/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0040BF50(int);

void func_003CB4F0(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = 0xbeba0000;
    v1 = v1 | 0xafde;
    a0 = *(int*)(char*)(a0 + 12);
    a1 = *(int*)(char*)(a0 + 4);
    cond = a1 != v1;
    if (cond) goto L003CB518;
    v0 = func_0040BF50(a0);
L003CB518:;
    goto ret;
ret:;
}
