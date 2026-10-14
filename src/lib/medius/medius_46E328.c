/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005984C0[];
extern char D_005984C4[];

int func_0046E328(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984C0;
    cond = v0 == 0;
    if (cond) goto L0046E344;
    v0 = ((int (*)(void))v0)();
L0046E344:;
    v0 = 0 + 200;
    goto ret;
ret:
    return v0;
}

int func_0046E358(void) {
    return 472;
}

int func_0046E360(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984C4;
    cond = v0 == 0;
    if (cond) goto L0046E37C;
    v0 = ((int (*)(void))v0)();
L0046E37C:;
    v0 = 0 + 200;
    goto ret;
ret:
    return v0;
}
