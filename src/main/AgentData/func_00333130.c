/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00333170(int, int, int);

void func_00333130(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = func_00333170(a0, a1, a2);
    cond = v0 == 0;
    if (cond) goto L00333158;
    v1 = *(unsigned char*)(char*)v0;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L00333158;
    *(char*)(char*)v0 = v1;
L00333158:;
    goto ret;
ret:;
}
