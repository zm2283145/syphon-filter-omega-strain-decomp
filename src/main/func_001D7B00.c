/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001D7B00(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001D7B10(char* self) {
    return *(int*)(self + 8);
}
