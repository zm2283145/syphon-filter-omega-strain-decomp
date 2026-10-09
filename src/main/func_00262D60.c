/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00262D60(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

void* func_00262D70(char* self) {
    return self + 4;
}

void* func_00262D80(void* self) {
    return self;
}
