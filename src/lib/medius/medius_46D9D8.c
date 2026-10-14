/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DB4[];
extern char D_00497DB8[];

int func_0046D9D8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DB4;
    cond = v0 == 0;
    if (cond) goto L0046D9F4;
    v0 = ((int (*)(void))v0)();
L0046D9F4:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_0046DA08(void) {
    return 60;
}

int func_0046DA10(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DB8;
    cond = v0 == 0;
    if (cond) goto L0046DA2C;
    v0 = ((int (*)(void))v0)();
L0046DA2C:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}
