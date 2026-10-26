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

Word* cCollisionModel_TreeLink_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word differs from value. */
int cCollisionModel_TreeLink_opNe(Word* w, int value) {
    return (w->value ^ value) != 0;
}
