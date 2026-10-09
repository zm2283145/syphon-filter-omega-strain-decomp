/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005984B0[];
extern char D_005984B4[];

int func_0046E248(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984B0;
    cond = v0 == 0;
    if (cond) goto L0046E264;
    v0 = ((int (*)(void))v0)();
L0046E264:;
    v0 = 0 + 200;
    goto ret;
ret:
    return v0;
}

int func_0046E278(void) {
    return 196;
}

int func_0046E280(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984B4;
    cond = v0 == 0;
    if (cond) goto L0046E29C;
    v0 = ((int (*)(void))v0)();
L0046E29C:;
    v0 = 0 + 508;
    goto ret;
ret:
    return v0;
}
