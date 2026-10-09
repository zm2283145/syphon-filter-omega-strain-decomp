/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00393B90(char* self) {
    return *(int*)(self + 88);
}

int func_00393BA0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    return a0;
}
