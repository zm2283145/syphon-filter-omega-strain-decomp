/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0040BB70(char* self) {
    return *(int*)(self + 8);
}

int func_0040BB80(int a0) {
    return (*(int*)(char*)a0 + -4);
}

int func_0040BB90(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + -4);
    return a0;
}

int func_0040BBB0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}
