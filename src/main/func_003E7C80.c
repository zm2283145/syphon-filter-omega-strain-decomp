/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00493970[];
extern void func_003E7CB0(int);

int func_003E7C80(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    func_003E7CB0(a0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

void func_003E7CB0(int a0) {
    signed char tmp0;
    int tmp1;

    tmp0 = *(signed char*)(char*)a0;
    tmp1 = *(int*)D_00493970;
    *(char*)((char*)tmp1) = tmp0;
}

void func_003E7CD0(int a0) {
    *(char*)((char*)a0 + 1) = 0;
    *(char*)((char*)a0 + 2) = 1;
    *(int*)((char*)a0 + 4) = -7;
}
