/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(void*, int);

int std_vector_cSkeletonBBoxContributionPtr_reserve(void* self, int arg) {
    return std_vector_pod_int_reserve(self, arg);
}

Rel* std_vector_cSkeletonBBoxContributionPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_cSkeletonCenterOfMassContributionPtr_reserve(void* self, int arg) {
    return std_vector_pod_int_reserve(self, arg);
}

Rel* std_vector_cSkeletonCenterOfMassContributionPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
