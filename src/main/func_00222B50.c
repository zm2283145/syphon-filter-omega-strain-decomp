/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00222B50(char* self) {
    return self + 4;
}

int func_00222B60(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 8) = (a0 + 4);
    *(int*)((char*)a0 + 4) = (a0 + 4);
    return a0;
}
