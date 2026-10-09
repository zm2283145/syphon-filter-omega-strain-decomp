/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DA0[];
extern char D_00497DA4[];

int func_0046D818(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DA0;
    cond = v0 == 0;
    if (cond) goto L0046D834;
    v0 = ((int (*)(void))v0)();
L0046D834:;
    v0 = 0 + 40;
    goto ret;
ret:
    return v0;
}

int func_0046D848(void) {
    return 56;
}

int func_0046D850(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DA4;
    cond = v0 == 0;
    if (cond) goto L0046D86C;
    v0 = ((int (*)(void))v0)();
L0046D86C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
