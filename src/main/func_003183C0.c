/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003183C0(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)(a0 + 72);
    v0 = 0 + 1;
    *(short*)(char*)(v1 + 42) = v0;
    goto ret;
ret:
    return v0;
}

int func_003183D0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 72);
    *(short*)((char*)tmp0 + 42) = 0;
    return tmp0;
}

int func_003183E0(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)(a0 + 72);
    v0 = 0 + 1;
    *(short*)(char*)(v1 + 44) = v0;
    goto ret;
ret:
    return v0;
}

int func_003183F0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 72);
    *(short*)((char*)tmp0 + 44) = 0;
    return tmp0;
}
