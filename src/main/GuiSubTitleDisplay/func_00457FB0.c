/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0041E3B0(int, float);

int func_00457FB0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

void* func_00457FC0(char* self) {
    return self + 4;
}

void* func_00457FD0(void* self) {
    return self;
}

int func_00457FE0(int a0, float f12) {
    int tmp0;
    float tmp2;

    tmp0 = func_0041E3B0(a0, f12);
    tmp2 = *(float*)((char*)a0 + 84);
    *(float*)((char*)a0 + 84) = (tmp2 + (f12 / 30.0f));
    return tmp0;
}
