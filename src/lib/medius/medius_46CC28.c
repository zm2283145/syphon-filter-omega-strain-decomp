/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D38[];

int func_0046CC28(void) {
    return 148;
}

int func_0046CC30(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D38;
    cond = v0 == 0;
    if (cond) goto L0046CC4C;
    v0 = ((int (*)(void))v0)();
L0046CC4C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
