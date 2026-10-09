/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003CC460(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 68);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_003CC480(int a0) {
    int loc[1];
    int v0, v1;

    v1 = *(int*)(char*)(a0 + 4);
    v0 = 0;
    *(int*)(char*)loc = v1;
    v1 = *(int*)(char*)a0;
    a0 = *(int*)(char*)loc;
    *(int*)(char*)(v1 + 68) = a0;
    goto ret;
ret:
    return v0;
}
