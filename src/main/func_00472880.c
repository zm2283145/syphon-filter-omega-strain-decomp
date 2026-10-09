/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00471F90(int, int);

void* func_00472880(char* self) {
    return self + 4;
}

void func_00472890(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 == 0;
    if (cond) goto L004728A8;
    a0 = a1 + 4;
    a1 = 0 + -1;
    v0 = func_00471F90(a0, a1);
L004728A8:;
    goto ret;
ret:;
}

void* func_004728C0(void* self) {
    return self;
}
