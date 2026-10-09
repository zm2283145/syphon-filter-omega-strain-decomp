/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CA4D0(int, int);

void* func_003CAA00(char* self) {
    return self + 4;
}

void func_003CAA10(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 == 0;
    if (cond) goto L003CAA28;
    a0 = a1 + 4;
    a1 = 0 + -1;
    v0 = func_003CA4D0(a0, a1);
L003CAA28:;
    goto ret;
ret:;
}

void* func_003CAA40(void* self) {
    return self;
}
