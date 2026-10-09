/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598450[];
extern char D_00598454[];

int func_0046D428(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598450;
    cond = v0 == 0;
    if (cond) goto L0046D444;
    v0 = ((int (*)(void))v0)();
L0046D444:;
    v0 = 0 + 276;
    goto ret;
ret:
    return v0;
}

int func_0046D458(void) {
    return 248;
}

int func_0046D460(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598454;
    cond = v0 == 0;
    if (cond) goto L0046D47C;
    v0 = ((int (*)(void))v0)();
L0046D47C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
