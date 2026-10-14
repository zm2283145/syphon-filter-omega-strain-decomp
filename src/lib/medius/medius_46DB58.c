/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DD0[];
extern char D_00497DD4[];

int func_0046DB58(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DD0;
    cond = v0 == 0;
    if (cond) goto L0046DB74;
    v0 = ((int (*)(void))v0)();
L0046DB74:;
    v0 = 0 + 68;
    goto ret;
ret:
    return v0;
}

int func_0046DB88(void) {
    return 44;
}

int func_0046DB90(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DD4;
    cond = v0 == 0;
    if (cond) goto L0046DBAC;
    v0 = ((int (*)(void))v0)();
L0046DBAC:;
    v0 = 0 + 36;
    goto ret;
ret:
    return v0;
}
