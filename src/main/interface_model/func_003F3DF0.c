/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003F3DF0(int a0, int a1) {
    int a2, v0, v1;
    float f0, f1, f2;

    a2 = *(int*)(char*)a1;
    v0 = a0;
    v1 = a2 + 4;
    *(int*)(char*)a1 = v1;
    f0 = *(float*)(char*)a2;
    *(float*)(char*)a0 = f0;
    a2 = *(int*)(char*)a1;
    v1 = a2 + 12;
    *(int*)(char*)a1 = v1;
    f2 = *(float*)(char*)(a2 + 4);
    f1 = *(float*)(char*)(a2 + 8);
    f0 = *(float*)(char*)a2;
    *(float*)(char*)(a0 + 4) = f0;
    *(float*)(char*)(a0 + 8) = f2;
    *(float*)(char*)(a0 + 12) = f1;
    goto ret;
ret:
    return v0;
}

int func_003F3E30(int a0, int a1) {
    int a2, v0, v1;
    float f0, f1, f2;

    a2 = *(int*)(char*)a1;
    v0 = a0;
    v1 = a2 + 4;
    *(int*)(char*)a1 = v1;
    f0 = *(float*)(char*)a2;
    *(float*)(char*)a0 = f0;
    a2 = *(int*)(char*)a1;
    v1 = a2 + 12;
    *(int*)(char*)a1 = v1;
    f2 = *(float*)(char*)(a2 + 4);
    f1 = *(float*)(char*)(a2 + 8);
    f0 = *(float*)(char*)a2;
    *(float*)(char*)(a0 + 4) = f0;
    *(float*)(char*)(a0 + 8) = f2;
    *(float*)(char*)(a0 + 12) = f1;
    goto ret;
ret:
    return v0;
}
