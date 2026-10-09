/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0012F5B0(int a0, int a1) {
    return *(int*)((char*)((a1 << 2) + a0) + 304);
}

void func_0012F5C0(int a0, int a1, int a2) {
    *(int*)((char*)((a1 << 2) + a0) + 304) = a2;
}

int func_0012F5D0(int a0, int a1) {
    return ((a0 + (a1 << 4)) + 240);
}
