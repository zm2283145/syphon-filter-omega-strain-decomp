/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497CB0[];

int func_0046DFC8(void) {
    return 141;
}

int func_0046DFD0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497CB0;
    cond = v0 == 0;
    if (cond) goto L0046DFEC;
    v0 = ((int (*)(void))v0)();
L0046DFEC:;
    v0 = 0 + 564;
    goto ret;
ret:
    return v0;
}
