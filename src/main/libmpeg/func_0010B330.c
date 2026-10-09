/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0010B330(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)(a0 + 64);
    v0 = 0 + 1;
    *(int*)(char*)(v1 + 4256) = v0;
    goto ret;
ret:
    return v0;
}

int func_0010B340(int a0, int a1, int a2, int a3) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    *(int*)((char*)tmp0 + 180) = a3;
    *(int*)((char*)tmp0 + 172) = a1;
    *(int*)((char*)tmp0 + 176) = a2;
    return tmp0;
}
