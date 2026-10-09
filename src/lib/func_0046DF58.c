/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497CAC[];

int func_0046DF58(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497CAC;
    cond = v0 == 0;
    if (cond) goto L0046DF74;
    v0 = ((int (*)(void))v0)();
L0046DF74:;
    v0 = 0 + 46;
    goto ret;
ret:
    return v0;
}

int func_0046DF88(void) {
    return 132;
}
