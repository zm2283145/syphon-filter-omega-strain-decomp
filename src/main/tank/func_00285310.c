/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern int func_00147840(int, int);
extern int func_003CC990(int, int, int);

int func_00285310(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 96);
    return func_003CC990(tmp0, a1, 0);
}

void func_00285320(int a0, int a1) {
    int s0, v0;
    int cond;

    s0 = *(int*)(char*)(a0 + 108);
    cond = s0 == 0;
    if (cond) goto L00285348;
    a0 = *(int*)(char*)D_004FFD30;
    *(int*)(char*)(s0 + 108) = a1;
    v0 = func_00147840(a0, a1);
    *(int*)(char*)(s0 + 104) = v0;
L00285348:;
    goto ret;
ret:;
}
