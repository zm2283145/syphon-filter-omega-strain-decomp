/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00598478[];
extern char D_0059847C[];

int func_0046D658(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059847C;
    cond = v0 == 0;
    if (cond) goto L0046D674;
    v0 = ((int (*)(void))v0)();
L0046D674:;
    v0 = 0 + 368;
    goto ret;
ret:
    return v0;
}

int func_0046D688(void) {
    return 60;
}

int func_0046D690(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00598478;
    cond = v0 == 0;
    if (cond) goto L0046D6AC;
    v0 = ((int (*)(void))v0)();
L0046D6AC:;
    v0 = 0 + 448;
    goto ret;
ret:
    return v0;
}
