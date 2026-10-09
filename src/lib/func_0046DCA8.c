/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DF4[];
extern char D_00497DF8[];

int func_0046DCA8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DF4;
    cond = v0 == 0;
    if (cond) goto L0046DCC4;
    v0 = ((int (*)(void))v0)();
L0046DCC4:;
    v0 = 0 + 208;
    goto ret;
ret:
    return v0;
}

int func_0046DCD8(void) {
    return 28;
}

int func_0046DCE0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DF8;
    cond = v0 == 0;
    if (cond) goto L0046DCFC;
    v0 = ((int (*)(void))v0)();
L0046DCFC:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
