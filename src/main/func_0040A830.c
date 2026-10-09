/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138350(int, int);

void* func_0040A830(char* self) {
    return self + 4;
}

void func_0040A840(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 == 0;
    if (cond) goto L0040A858;
    a0 = a1;
    a1 = 0 + -1;
    v0 = func_00138350(a0, a1);
L0040A858:;
    goto ret;
ret:;
}

void* func_0040A870(void* self) {
    return self;
}
