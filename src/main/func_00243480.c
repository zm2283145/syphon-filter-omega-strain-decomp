/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00243480(char* self, char value) {
    self[16] = value;
}

void func_00243490(char* self, char value) {
    self[91] = value;
}

int func_002434A0(char* self) {
    return *(int*)(self + 116);
}
