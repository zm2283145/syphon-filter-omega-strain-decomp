/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598488[];
extern char D_0059848C[];

int func_0046D738(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598488;
    cond = v0 == 0;
    if (cond) goto L0046D754;
    v0 = ((int (*)(void))v0)();
L0046D754:;
    v0 = 0 + 40;
    goto ret;
ret:
    return v0;
}

int func_0046D768(void) {
    return 300;
}

int func_0046D770(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059848C;
    cond = v0 == 0;
    if (cond) goto L0046D78C;
    v0 = ((int (*)(void))v0)();
L0046D78C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
