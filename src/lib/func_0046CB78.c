/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D24[];

int func_0046CB78(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D24;
    cond = v0 == 0;
    if (cond) goto L0046CB94;
    v0 = ((int (*)(void))v0)();
L0046CB94:;
    v0 = 0 + 196;
    goto ret;
ret:
    return v0;
}

int func_0046CBA8(void) {
    return 176;
}
