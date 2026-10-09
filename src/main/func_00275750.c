/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);
extern int func_00275780(int, int);

void func_00275750(int a0, int a1) {
    int loc[1];
    int v0;

    a0 = a0 + 120;
    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    v0 = func_00275780(a0, a1);
    goto ret;
ret:;
}

int func_00275780(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
