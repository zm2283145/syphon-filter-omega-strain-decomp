/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int opNe_cConstLListIteratorR_cConstLListIteratorR(Iter* a, Iter* b) {
    return a->p != b->p;
}

/* List iterator ++: follow the next link at node +0x04. */
Iter* cConstLListIterator_cSkaPlaybackGroupPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
