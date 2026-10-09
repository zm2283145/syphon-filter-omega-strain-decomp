/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003C9B20(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

void* func_003C9B30(char* self) {
    return self + 4;
}

void* func_003C9B40(void* self) {
    return self;
}
