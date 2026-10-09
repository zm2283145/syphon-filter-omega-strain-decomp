/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138350(int, int);

void* func_00419CC0(char* self) {
    return self + 4;
}

void func_00419CD0(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 == 0;
    if (cond) goto L00419CE8;
    a0 = a1;
    a1 = 0 + -1;
    v0 = func_00138350(a0, a1);
L00419CE8:;
    goto ret;
ret:;
}

void* func_00419D00(void* self) {
    return self;
}
