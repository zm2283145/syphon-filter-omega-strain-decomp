/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005984C8[];
extern char D_005984CC[];

int func_0046E398(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984C8;
    cond = v0 == 0;
    if (cond) goto L0046E3B4;
    v0 = ((int (*)(void))v0)();
L0046E3B4:;
    v0 = 0 + 476;
    goto ret;
ret:
    return v0;
}

int func_0046E3C8(void) {
    return 508;
}

int func_0046E3D0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984CC;
    cond = v0 == 0;
    if (cond) goto L0046E3EC;
    v0 = ((int (*)(void))v0)();
L0046E3EC:;
    v0 = 0 + 200;
    goto ret;
ret:
    return v0;
}
