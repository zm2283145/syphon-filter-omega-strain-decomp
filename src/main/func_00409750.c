/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00409750(int a0) {
    int a1, v0, v1;

    *(int*)(char*)a0 = 0;
    v0 = 0x3e4c0000;
    *(int*)(char*)(a0 + 4) = 0;
    v1 = v0 | 0xcccd;
    a1 = 0 + -1;
    *(int*)(char*)(a0 + 8) = 0;
    *(int*)(char*)(a0 + 12) = a1;
    v0 = a0;
    *(int*)(char*)(a0 + 16) = a1;
    *(int*)(char*)(a0 + 20) = 0;
    *(int*)(char*)(a0 + 24) = 0;
    *(int*)(char*)(a0 + 28) = 0;
    *(int*)(char*)(a0 + 32) = 0;
    *(int*)(char*)(a0 + 36) = 0;
    *(int*)(char*)(a0 + 40) = 0;
    *(int*)(char*)(a0 + 44) = a1;
    *(int*)(char*)(a0 + 48) = v1;
    *(char*)(char*)(a0 + 52) = 0;
    goto ret;
ret:
    return v0;
}
