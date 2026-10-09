/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E0F80(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (a1 << 4));
}

int func_001E0F90(char* self) {
    return *(int*)(self + 4);
}

int func_001E0FA0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

int func_001E0FC0(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 96);
    return a0;
}
