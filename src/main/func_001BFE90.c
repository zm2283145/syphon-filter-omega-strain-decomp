/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001BFE90(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

int func_001BFEB0(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 1);
    return a0;
}

int func_001BFED0(char* self) {
    return *(int*)(self + 0);
}
