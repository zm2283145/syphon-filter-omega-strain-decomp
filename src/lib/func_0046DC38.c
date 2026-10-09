/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598494[];
extern char D_00598498[];

int func_0046DC38(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598494;
    cond = v0 == 0;
    if (cond) goto L0046DC54;
    v0 = ((int (*)(void))v0)();
L0046DC54:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}

int func_0046DC68(void) {
    return 36;
}

int func_0046DC70(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598498;
    cond = v0 == 0;
    if (cond) goto L0046DC8C;
    v0 = ((int (*)(void))v0)();
L0046DC8C:;
    v0 = 0 + 36;
    goto ret;
ret:
    return v0;
}
