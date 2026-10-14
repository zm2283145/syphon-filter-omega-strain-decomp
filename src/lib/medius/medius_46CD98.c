/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D2C[];
extern char D_00497D4C[];

int func_0046CD98(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D2C;
    cond = v0 == 0;
    if (cond) goto L0046CDB4;
    v0 = ((int (*)(void))v0)();
L0046CDB4:;
    v0 = 0 + 328;
    goto ret;
ret:
    return v0;
}

int func_0046CDC8(void) {
    return 44;
}

int func_0046CDD0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D4C;
    cond = v0 == 0;
    if (cond) goto L0046CDEC;
    v0 = ((int (*)(void))v0)();
L0046CDEC:;
    v0 = 0 + 328;
    goto ret;
ret:
    return v0;
}
