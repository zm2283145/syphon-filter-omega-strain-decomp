/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D44[];

int func_0046CCE8(void) {
    return 48;
}

int func_0046CCF0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D44;
    cond = v0 == 0;
    if (cond) goto L0046CD0C;
    v0 = ((int (*)(void))v0)();
L0046CD0C:;
    v0 = 0 + 112;
    goto ret;
ret:
    return v0;
}
