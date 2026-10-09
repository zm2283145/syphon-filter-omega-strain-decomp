/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00330820(char* self) {
    return self + 8;
}

int func_00330830(Iter* a, Iter* b) {
    return !(a->p == b->p);
}
