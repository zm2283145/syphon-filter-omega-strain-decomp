/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E08[];

int func_0046DDF8(void) {
    return 40;
}

int func_0046DE00(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E08;
    cond = v0 == 0;
    if (cond) goto L0046DE1C;
    v0 = ((int (*)(void))v0)();
L0046DE1C:;
    v0 = 0 + 472;
    goto ret;
ret:
    return v0;
}
