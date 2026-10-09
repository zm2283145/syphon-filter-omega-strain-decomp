/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E0F90(char* self) {
    return *(int*)(self + 4);
}

int func_001E0FA0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}
