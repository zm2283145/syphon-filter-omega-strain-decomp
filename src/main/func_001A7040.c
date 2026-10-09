/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_001A7040(PtrVec* v) {
    return v->data + v->count;
}

int func_001A7060(char* self) {
    return *(int*)(self + 8);
}

void* func_001A7070(void* self) {
    return self;
}
