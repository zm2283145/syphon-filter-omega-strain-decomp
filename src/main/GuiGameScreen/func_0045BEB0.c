/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00424430(int, int, int);

void func_0045BEB0(char* self, int value) {
    *(int*)(self + 236) = value;
}

void func_0045BEC0(int a0, int a1) {
    int a2, at, v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 224);
    cond = v1 == 0;
    a2 = a1;
    if (cond) goto L0045BEF8;
    cond = a2 <= 0;
    if (cond) goto L0045BEF8;
    a0 = *(int*)(char*)(a0 + 232);
    v1 = *(int*)(char*)(a0 + 148);
    at = a2 < v1;
    cond = at == 0;
    a1 = 0;
    if (cond) goto L0045BEF8;
    v0 = func_00424430(a0, a1, a2);
L0045BEF8:;
    goto ret;
ret:;
}
