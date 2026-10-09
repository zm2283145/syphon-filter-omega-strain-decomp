/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001260F0(int, int, int);
extern void func_0042B420(int);
extern int func_00438A70(int, int);

void func_00454010(int a0) {
    func_001260F0(a0, 0, 84);
    func_0042B420(a0);
}

void func_00454050(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)(a0 + 9173);
    cond = v1 != 0;
    if (cond) goto L00454070;
    a0 = *(int*)(char*)(a0 + 384);
    a1 = 0;
    v0 = func_00438A70(a0, a1);
L00454070:;
    goto ret;
ret:;
}
