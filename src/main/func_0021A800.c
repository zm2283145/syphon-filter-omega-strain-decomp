/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9DE0[];

int func_0021A800(int a0) {
    *(int*)((char*)a0 + 4) = -2;
    *(int*)((char*)a0) = 0;
    return a0;
}

int func_0021A820(int a0, int a1, int a2, int a3) {
    *(int*)((char*)a0 + 8) = (int)D_004D9DE0;
    *(char*)((char*)a0 + 4) = a2;
    *(int*)((char*)a0) = a1;
    *(char*)((char*)a0 + 5) = a3;
    return a0;
}
