/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00190F00(char* self) {
    return *(int*)(self + 4);
}

int func_00190F10(char* self) {
    return *(int*)(self + 0);
}

int* func_00190F20(int* self, int value) {
    *self = value;
    return self;
}

int func_00190F30(char* self) {
    return *(int*)(self + 0);
}

int func_00190F40(char* self) {
    return *(int*)(self + 32);
}
