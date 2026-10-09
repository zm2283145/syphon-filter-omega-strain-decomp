/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DE670[];
extern int func_0041E470(int);
extern int func_0041EFA0(int);
extern void func_0041F690(int);

void func_00326810(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = func_0041E470(a0);
    v1 = *(int*)(char*)(s0 + 72);
    cond = v1 == 0;
    if (cond) goto L00326838;
    v0 = ((int (*)(void))v1)();
L00326838:;
    goto ret;
ret:;
}

int func_00326850(int a0) {
    return func_0041EFA0(a0);
}

int func_00326860(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DE670;
    *(int*)((char*)a0 + 72) = 0;
    return a0;
}
