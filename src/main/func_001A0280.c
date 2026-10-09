/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001A0280(char* self) {
    return *(int*)(self + 176);
}

int func_001A0290(int a0) {
    return ((*(int*)((char*)a0 + 8) + (*(int*)((char*)a0 + 4) << 2)) + -4);
}
