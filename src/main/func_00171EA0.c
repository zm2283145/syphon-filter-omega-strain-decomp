/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_00171EA0(PtrVec* v, int i) {
    return v->data + i;
}

int func_00171EB0(char* self) {
    return *(int*)(self + 4);
}

void* func_00171EC0(char* self) {
    return self + 8;
}
