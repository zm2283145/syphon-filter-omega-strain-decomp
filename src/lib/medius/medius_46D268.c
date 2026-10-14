/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598430[];
extern char D_00598438[];

int func_0046D268(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598430;
    cond = v0 == 0;
    if (cond) goto L0046D284;
    v0 = ((int (*)(void))v0)();
L0046D284:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D298(void) {
    return 48;
}

int func_0046D2A0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598438;
    cond = v0 == 0;
    if (cond) goto L0046D2BC;
    v0 = ((int (*)(void))v0)();
L0046D2BC:;
    v0 = 0 + 360;
    goto ret;
ret:
    return v0;
}
