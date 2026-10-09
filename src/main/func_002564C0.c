/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002564C0(int a0, int a1) {
    return ((unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)) < (unsigned int)(1));
}

void func_002564E0(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 8) + (*(int*)((char*)a1 + 4) << 3));
}
