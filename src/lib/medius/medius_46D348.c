/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598440[];
extern char D_00598444[];

int func_0046D348(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598440;
    cond = v0 == 0;
    if (cond) goto L0046D364;
    v0 = ((int (*)(void))v0)();
L0046D364:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D378(void) {
    return 48;
}

int func_0046D380(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598444;
    cond = v0 == 0;
    if (cond) goto L0046D39C;
    v0 = ((int (*)(void))v0)();
L0046D39C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
