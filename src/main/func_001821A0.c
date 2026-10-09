/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int ColTree_IsLeaf(Leaf* l, int* addr) {
    return *addr >= l->limit;
}

Word* func_001821C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word differs from value. */
int func_001821D0(Word* w, int value) {
    return (w->value ^ value) != 0;
}
