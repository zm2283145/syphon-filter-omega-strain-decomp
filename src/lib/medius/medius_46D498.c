/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598458[];
extern char D_0059846C[];

int func_0046D498(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598458;
    cond = v0 == 0;
    if (cond) goto L0046D4B4;
    v0 = ((int (*)(void))v0)();
L0046D4B4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D4C8(void) {
    return 244;
}

int func_0046D4D0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059846C;
    cond = v0 == 0;
    if (cond) goto L0046D4EC;
    v0 = ((int (*)(void))v0)();
L0046D4EC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
