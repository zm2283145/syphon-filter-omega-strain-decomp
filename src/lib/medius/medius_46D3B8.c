/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598448[];
extern char D_0059844C[];

int func_0046D3B8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598448;
    cond = v0 == 0;
    if (cond) goto L0046D3D4;
    v0 = ((int (*)(void))v0)();
L0046D3D4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D3E8(void) {
    return 48;
}

int func_0046D3F0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059844C;
    cond = v0 == 0;
    if (cond) goto L0046D40C;
    v0 = ((int (*)(void))v0)();
L0046D40C:;
    v0 = 0 + 280;
    goto ret;
ret:
    return v0;
}
