/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506550[];
extern int func_002A2590(int);

void func_002A5440(int a0, int a1) {
    int v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 13700);
    cond = v1 == 0;
    if (cond) goto L002A5450;
    *(char*)(char*)(v1 + 50) = a1;
L002A5450:;
    goto ret;
ret:;
}

int func_002A5460(void) {
    int tmp0;

    tmp0 = *(int*)D_00506550;
    return func_002A2590(tmp0);
}
