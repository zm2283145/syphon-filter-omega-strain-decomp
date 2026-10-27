/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(Iter* it) {
    it->p++;
    return it;
}
