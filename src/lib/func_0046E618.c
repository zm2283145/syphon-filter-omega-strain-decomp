/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E38[];
extern char D_00497E3C[];

int func_0046E618(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E38;
    cond = v0 == 0;
    if (cond) goto L0046E634;
    v0 = ((int (*)(void))v0)();
L0046E634:;
    v0 = 0 + 24;
    goto ret;
ret:
    return v0;
}

int func_0046E648(void) {
    return 136;
}

int func_0046E650(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E3C;
    cond = v0 == 0;
    if (cond) goto L0046E66C;
    v0 = ((int (*)(void))v0)();
L0046E66C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
