/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013A820(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

int func_0013A840(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 224);
    return a0;
}

int func_0013A860(char* self) {
    return *(int*)(self + 0);
}
