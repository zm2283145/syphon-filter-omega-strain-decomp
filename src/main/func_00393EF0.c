/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00393F60(int);
extern int func_00395EB0(int, int, int);

int func_00393EF0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 12) = 0;
    return a0;
}

int func_00393F10(int a0) {
    int v0, v1;

    *(int*)(char*)a0 = 0;
    v0 = 0x7f7f0000;
    v1 = v0 | 0xffff;
    *(int*)(char*)(a0 + 4) = 0;
    *(int*)(char*)(a0 + 8) = v1;
    v0 = a0;
    *(int*)(char*)(a0 + 12) = v1;
    goto ret;
ret:
    return v0;
}

int func_00393F30(int a0) {
    int s0, v0, v1;

    s0 = a0;
    v0 = func_00393F60(a0);
    v1 = 0 + 1;
    v0 = s0;
    *(char*)(char*)(s0 + 12) = v1;
    goto ret;
ret:
    return v0;
}

int func_00393F60(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_00395EB0(a0, a1, a2);
    return a0;
}
