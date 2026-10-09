/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003B24C0(void* self) {
    return self;
}

int func_003B24D0(char* self) {
    return *(int*)(self + 0);
}

void func_003B24E0(int a0, float f12, float f13) {
    *(float*)((char*)a0 + 256) = (*(float*)((char*)a0 + 256) + (f12 * f13));
}

int func_003B2500(char* self) {
    return *(int*)(self + 0);
}
