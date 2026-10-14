/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E10[];

int func_0046DE48(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E10;
    cond = v0 == 0;
    if (cond) goto L0046DE64;
    v0 = ((int (*)(void))v0)();
L0046DE64:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046DE78(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E10;
    cond = v0 == 0;
    if (cond) goto L0046DE94;
    v0 = ((int (*)(void))v0)();
L0046DE94:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046DEA8(void) {
    return 28;
}
