/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D98[];
extern char D_00497D9C[];

int func_0046D7A8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D9C;
    cond = v0 == 0;
    if (cond) goto L0046D7C4;
    v0 = ((int (*)(void))v0)();
L0046D7C4:;
    v0 = 0 + 48;
    goto ret;
ret:
    return v0;
}

int func_0046D7D8(void) {
    return 38;
}

int func_0046D7E0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D98;
    cond = v0 == 0;
    if (cond) goto L0046D7FC;
    v0 = ((int (*)(void))v0)();
L0046D7FC:;
    v0 = 0 + 77;
    goto ret;
ret:
    return v0;
}
