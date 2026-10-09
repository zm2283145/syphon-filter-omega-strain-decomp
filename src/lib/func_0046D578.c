/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598464[];
extern char D_00598468[];

int func_0046D578(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598464;
    cond = v0 == 0;
    if (cond) goto L0046D594;
    v0 = ((int (*)(void))v0)();
L0046D594:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D5A8(void) {
    return 44;
}

int func_0046D5B0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598468;
    cond = v0 == 0;
    if (cond) goto L0046D5CC;
    v0 = ((int (*)(void))v0)();
L0046D5CC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
