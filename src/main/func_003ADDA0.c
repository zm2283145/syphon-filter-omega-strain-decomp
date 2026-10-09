/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003ADDA0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

int func_003ADDC0(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 32);
    return a0;
}
