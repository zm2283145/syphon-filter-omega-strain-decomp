/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D40[];

int func_0046CCA8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D40;
    cond = v0 == 0;
    if (cond) goto L0046CCC4;
    v0 = ((int (*)(void))v0)();
L0046CCC4:;
    v0 = 0 + 184;
    goto ret;
ret:
    return v0;
}

int func_0046CCD8(void) {
    return 38;
}
