/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E40[];
extern char D_00497E44[];

int func_0046E688(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E40;
    cond = v0 == 0;
    if (cond) goto L0046E6A4;
    v0 = ((int (*)(void))v0)();
L0046E6A4:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_0046E6B8(void) {
    return 32;
}

int func_0046E6C0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E44;
    cond = v0 == 0;
    if (cond) goto L0046E6DC;
    v0 = ((int (*)(void))v0)();
L0046E6DC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
