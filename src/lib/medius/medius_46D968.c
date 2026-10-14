/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DB0[];
extern char D_00598490[];

int func_0046D968(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598490;
    cond = v0 == 0;
    if (cond) goto L0046D984;
    v0 = ((int (*)(void))v0)();
L0046D984:;
    v0 = 0 + 68;
    goto ret;
ret:
    return v0;
}

int func_0046D998(void) {
    return 56;
}

int func_0046D9A0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DB0;
    cond = v0 == 0;
    if (cond) goto L0046D9BC;
    v0 = ((int (*)(void))v0)();
L0046D9BC:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
