/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497CF4[];

void func_0046C858(void) {

}

int func_0046C860(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497CF4;
    cond = v0 == 0;
    if (cond) goto L0046C87C;
    v0 = ((int (*)(void))v0)();
L0046C87C:;
    v0 = 0 + 260;
    goto ret;
ret:
    return v0;
}
