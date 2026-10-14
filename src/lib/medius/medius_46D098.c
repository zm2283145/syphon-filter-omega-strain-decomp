/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D7C[];
extern char D_00497D80[];

int func_0046D098(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D7C;
    cond = v0 == 0;
    if (cond) goto L0046D0B4;
    v0 = ((int (*)(void))v0)();
L0046D0B4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046D0C8(void) {
    return 44;
}

int func_0046D0D0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D80;
    cond = v0 == 0;
    if (cond) goto L0046D0EC;
    v0 = ((int (*)(void))v0)();
L0046D0EC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
