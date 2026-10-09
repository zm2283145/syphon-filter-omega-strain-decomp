/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_003DC4C0(PtrVec* v, int i) {
    return v->data + i;
}

int func_003DC4D0(int a0, int a1) {
    return *(int*)(char*)(*(int*)((char*)a0 + 72) + ((a1 + -10) << 2));
}
