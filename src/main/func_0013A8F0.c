/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

unsigned char func_0013A8F0(unsigned char* self) {
    return self[32];
}

int func_0013A900(char* self) {
    return *(int*)(self + 0);
}

void func_0013A910(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 8) + (((*(int*)((char*)a1 + 4) << 3) - *(int*)((char*)a1 + 4)) << 5));
}

void func_0013A930(Iter* out, PtrVec* v) {
    out->p = v->data;
}
