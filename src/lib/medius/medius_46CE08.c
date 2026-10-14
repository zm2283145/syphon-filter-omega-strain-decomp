/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D50[];
extern char D_00497D54[];

int func_0046CE08(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D50;
    cond = v0 == 0;
    if (cond) goto L0046CE24;
    v0 = ((int (*)(void))v0)();
L0046CE24:;
    v0 = 0 + 396;
    goto ret;
ret:
    return v0;
}

int func_0046CE38(void) {
    return 44;
}

int func_0046CE40(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D54;
    cond = v0 == 0;
    if (cond) goto L0046CE5C;
    v0 = ((int (*)(void))v0)();
L0046CE5C:;
    v0 = 0 + 100;
    goto ret;
ret:
    return v0;
}
