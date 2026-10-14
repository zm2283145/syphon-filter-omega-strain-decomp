/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E00[];
extern char D_00497E04[];

int func_0046DD88(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E00;
    cond = v0 == 0;
    if (cond) goto L0046DDA4;
    v0 = ((int (*)(void))v0)();
L0046DDA4:;
    v0 = 0 + 400;
    goto ret;
ret:
    return v0;
}

int func_0046DDB8(void) {
    return 26;
}

int func_0046DDC0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E04;
    cond = v0 == 0;
    if (cond) goto L0046DDDC;
    v0 = ((int (*)(void))v0)();
L0046DDDC:;
    v0 = 0 + 112;
    goto ret;
ret:
    return v0;
}
