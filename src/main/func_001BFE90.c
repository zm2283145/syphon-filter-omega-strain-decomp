/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int func_001BFE90(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance a byte iterator. */
ByteIter* func_001BFEB0(ByteIter* it) {
    it->p = it->p + 1;
    return it;
}

unsigned char* func_001BFED0(ByteIter* it) {
    return it->p;
}
