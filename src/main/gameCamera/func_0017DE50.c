/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Random_Next(void);

int func_0017DE50(int a0, float f12, float f13, float f14) {
    *(float*)((char*)a0) = f12;
    *(float*)((char*)a0 + 4) = f13;
    *(float*)((char*)a0 + 8) = f14;
    return a0;
}

int func_0017DE70(void) {
    return Random_Next();
}

float func_0017DE80(char* self) {
    return *(float*)(self + 8);
}

void* func_0017DE90(char* self) {
    return self + 8;
}
