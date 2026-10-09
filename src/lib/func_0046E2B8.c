/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005984B8[];
extern char D_005984BC[];

int func_0046E2B8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984B8;
    cond = v0 == 0;
    if (cond) goto L0046E2D4;
    v0 = ((int (*)(void))v0)();
L0046E2D4:;
    v0 = 0 + 508;
    goto ret;
ret:
    return v0;
}

int func_0046E2E8(void) {
    return 196;
}

int func_0046E2F0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984BC;
    cond = v0 == 0;
    if (cond) goto L0046E30C;
    v0 = ((int (*)(void))v0)();
L0046E30C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
