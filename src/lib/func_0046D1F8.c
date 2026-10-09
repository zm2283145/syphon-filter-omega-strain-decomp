/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D94[];
extern char D_0059842C[];

int func_0046D1F8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D94;
    cond = v0 == 0;
    if (cond) goto L0046D214;
    v0 = ((int (*)(void))v0)();
L0046D214:;
    v0 = 0 + 44;
    goto ret;
ret:
    return v0;
}

int func_0046D228(void) {
    return 76;
}

int func_0046D230(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059842C;
    cond = v0 == 0;
    if (cond) goto L0046D24C;
    v0 = ((int (*)(void))v0)();
L0046D24C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
