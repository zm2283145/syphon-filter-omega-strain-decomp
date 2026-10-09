/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern float func_003D08B0(int, int);

void func_003E7EB0(char* self, int value) {
    *(int*)(self + 120) = value;
}

float func_003E7EC0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 116);
    return func_003D08B0(tmp0, a1);
}
