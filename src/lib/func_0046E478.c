/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DE0[];
extern char D_005984D8[];

int func_0046E478(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984D8;
    cond = v0 == 0;
    if (cond) goto L0046E494;
    v0 = ((int (*)(void))v0)();
L0046E494:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046E4A8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DE0;
    cond = v0 == 0;
    if (cond) goto L0046E4C4;
    v0 = ((int (*)(void))v0)();
L0046E4C4:;
    v0 = 0 + 36;
    goto ret;
ret:
    return v0;
}
