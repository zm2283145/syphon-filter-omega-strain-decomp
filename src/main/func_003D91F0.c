/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);
extern int func_003D9240(int);
extern int func_003D9470(int, int, int);

int func_003D91F0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

int func_003D9210(int a0) {
    int s0, v0, v1;

    s0 = a0;
    v0 = func_003D9240(a0);
    v1 = 0 + 1;
    v0 = s0;
    *(char*)(char*)(s0 + 12) = v1;
    goto ret;
ret:
    return v0;
}

int func_003D9240(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_003D9470(a0, a1, a2);
    return a0;
}
