/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00492BB0[];
extern int func_0034BAE8(int, int, int, int, int);
extern int func_0034BB80(int, int, int, int, int);

void func_0034BCE0(int a0, int a1, int a2, int a3, int t0, int t1) {
    int v0;
    int cond;

    t1 = t1 & 2;
    cond = t1 == 0;
    if (cond) goto L0034BD00;
    v0 = func_0034BAE8(a0, a1, a2, a3, t0);
    goto L0034BD0C;
L0034BD00:;
    v0 = func_0034BB80(a0, a1, a2, a3, t0);
L0034BD0C:;
    goto ret;
ret:;
}

int func_0034BD18(void) {
    int tmp0;

    tmp0 = *(int*)D_00492BB0;
    return tmp0;
}
