/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D78[];

int func_0046D058(void) {
    return 38;
}

int func_0046D060(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D78;
    cond = v0 == 0;
    if (cond) goto L0046D07C;
    v0 = ((int (*)(void))v0)();
L0046D07C:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}
