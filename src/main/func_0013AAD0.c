/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void LosResult_SetStatus(char* self, char value) {
    self[0] = value;
}

int func_0013AAE0(int a0) {
    *(char*)((char*)a0 + 64) = 0;
    *(char*)((char*)a0 + 66) = 0;
    *(int*)((char*)a0 + 96) = 0;
    *(int*)((char*)a0 + 100) = 0;
    return a0;
}

void* Ptr_Identity(void* self) {
    return self;
}
