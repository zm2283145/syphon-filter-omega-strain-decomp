/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DC8[];
extern char D_00497DCC[];

int func_0046DAE8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DC8;
    cond = v0 == 0;
    if (cond) goto L0046DB04;
    v0 = ((int (*)(void))v0)();
L0046DB04:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_0046DB18(void) {
    return 44;
}

int func_0046DB20(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DCC;
    cond = v0 == 0;
    if (cond) goto L0046DB3C;
    v0 = ((int (*)(void))v0)();
L0046DB3C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
