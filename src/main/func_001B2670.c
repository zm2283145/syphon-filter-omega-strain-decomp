/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001B2670(char* self) {
    *(int*)(self + 8) = 0;
}

void func_001B2680(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)a0 + 4);
    *(int*)((char*)a0 + 4) = *(int*)((char*)a0 + 8);
}
