/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00452FC0(char* self, int value) {
    *(int*)(self + 9552) = value;
}

int func_00452FD0(int a0) {
    return ((unsigned int)((*(unsigned char*)((char*)a0 + 9572) ^ 5)) < (unsigned int)(1));
}

int func_00452FE0(char* self) {
    return *(int*)(self + 9584);
}
