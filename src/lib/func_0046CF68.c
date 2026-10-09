/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D68[];
extern char D_00497D6C[];

int func_0046CF68(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D68;
    cond = v0 == 0;
    if (cond) goto L0046CF84;
    v0 = ((int (*)(void))v0)();
L0046CF84:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046CF98(void) {
    return 44;
}

int func_0046CFA0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D6C;
    cond = v0 == 0;
    if (cond) goto L0046CFBC;
    v0 = ((int (*)(void))v0)();
L0046CFBC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
