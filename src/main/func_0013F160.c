/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013F160(int a0) {
    return (*(int*)(char*)a0 + 16);
}

void func_0013F170(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

int func_0013F180(int a0, int a1, int a2) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)(char*)a2;
    return a0;
}
