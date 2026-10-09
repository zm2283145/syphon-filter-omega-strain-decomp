/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00426590(int, int, int);

void func_00425C90(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = func_00426590(a0, a1, a2);
    cond = v0 == 0;
    if (cond) goto L00425CB8;
    a0 = *(int*)(char*)(v0 + 12);
    v1 = 0 + -2;
    v1 = a0 & v1;
    *(int*)(char*)(v0 + 12) = v1;
L00425CB8:;
    goto ret;
ret:;
}
