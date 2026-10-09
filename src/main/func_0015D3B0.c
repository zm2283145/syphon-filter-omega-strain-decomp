/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0015D3B0(int a0) {
    return (*(int*)((char*)a0 + 8) + (*(int*)((char*)a0 + 4) << 3));
}

void func_0015D3D0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_0015D3E0(char* self) {
    return *(int*)(self + 8);
}
