/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003F1E10(char* self, int value) {
    *(int*)(self + 28) = value;
}

int* func_003F1E20(PtrVec* v, int i) {
    return v->data + i;
}

int func_003F1E30(char* self) {
    return *(int*)(self + 4);
}
