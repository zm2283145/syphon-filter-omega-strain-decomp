/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598434[];
extern char D_0059843C[];

int func_0046D2D8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598434;
    cond = v0 == 0;
    if (cond) goto L0046D2F4;
    v0 = ((int (*)(void))v0)();
L0046D2F4:;
    v0 = 0 + 328;
    goto ret;
ret:
    return v0;
}

int func_0046D308(void) {
    return 76;
}

int func_0046D310(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059843C;
    cond = v0 == 0;
    if (cond) goto L0046D32C;
    v0 = ((int (*)(void))v0)();
L0046D32C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
