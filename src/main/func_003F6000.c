/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003F6000(int a0) {
    return ((unsigned int)((*(int*)((char*)a0 + 12) ^ *(int*)((char*)a0 + 16))) < (unsigned int)(1));
}

void func_003F6020(int a0) {
    *(int*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 8) = 0;
}

void func_003F6030(void) {
}
