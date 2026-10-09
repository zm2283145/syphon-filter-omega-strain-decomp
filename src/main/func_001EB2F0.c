/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001EB2F0(int a0) {
    *(char*)((char*)a0 + 48) = 0;
    *(int*)((char*)a0 + 80) = -1;
    *(int*)((char*)a0 + 84) = -1;
    *(int*)((char*)a0 + 88) = 0;
    return a0;
}

int func_001EB310(int a0, int a1, int a2, int a3, int t0) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)(char*)a2;
    *(int*)((char*)a0 + 8) = *(int*)(char*)a3;
    *(int*)((char*)a0 + 12) = *(int*)(char*)t0;
    return a0;
}
