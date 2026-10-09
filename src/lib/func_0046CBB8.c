/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D30[];
extern char D_00497D34[];

int func_0046CBB8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D30;
    cond = v0 == 0;
    if (cond) goto L0046CBD4;
    v0 = ((int (*)(void))v0)();
L0046CBD4:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_0046CBE8(void) {
    return 236;
}

int func_0046CBF0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D34;
    cond = v0 == 0;
    if (cond) goto L0046CC0C;
    v0 = ((int (*)(void))v0)();
L0046CC0C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
