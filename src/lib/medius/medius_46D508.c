/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0059845C[];
extern char D_00598460[];

int func_0046D508(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059845C;
    cond = v0 == 0;
    if (cond) goto L0046D524;
    v0 = ((int (*)(void))v0)();
L0046D524:;
    v0 = 0 + 236;
    goto ret;
ret:
    return v0;
}

int func_0046D538(void) {
    return 238;
}

int func_0046D540(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598460;
    cond = v0 == 0;
    if (cond) goto L0046D55C;
    v0 = ((int (*)(void))v0)();
L0046D55C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
