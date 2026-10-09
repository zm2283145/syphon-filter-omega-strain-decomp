/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0012F280(char* self, float value) {
    *(float*)(self + 212) = value;
}

float func_0012F290(char* self) {
    return *(float*)(self + 212);
}

void* func_0012F2A0(char* self) {
    return self + 1;
}

void* func_0012F2B0(char* self) {
    return self + 12;
}

int func_0012F2C0(char* self) {
    return *(int*)(self + 220);
}
