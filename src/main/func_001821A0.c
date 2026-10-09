/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int ColTree_IsLeaf(Leaf* l, int* addr) {
    return *addr >= l->limit;
}

Word* func_001821C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_001821D0(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ a1)));
}
