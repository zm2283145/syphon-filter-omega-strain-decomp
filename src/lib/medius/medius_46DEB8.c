/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E0C[];
extern char D_00497E14[];
extern char D_00497E18[];

int func_0046DEB8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E14;
    cond = v0 == 0;
    if (cond) goto L0046DED4;
    v0 = ((int (*)(void))v0)();
L0046DED4:;
    v0 = 0 + 88;
    goto ret;
ret:
    return v0;
}

int func_0046DEE8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E18;
    cond = v0 == 0;
    if (cond) goto L0046DF04;
    v0 = ((int (*)(void))v0)();
L0046DF04:;
    v0 = 0 + 432;
    goto ret;
ret:
    return v0;
}

int func_0046DF18(void) {
    return 36;
}

int func_0046DF20(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E0C;
    cond = v0 == 0;
    if (cond) goto L0046DF3C;
    v0 = ((int (*)(void))v0)();
L0046DF3C:;
    v0 = 0 + 36;
    goto ret;
ret:
    return v0;
}
