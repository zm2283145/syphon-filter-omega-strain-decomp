/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003F5CE0(char* self) {
    return *(int*)(self + 168);
}

void func_003F5CF0(int a0) {
    *(int*)((char*)a0 + 168) = 1;
}
