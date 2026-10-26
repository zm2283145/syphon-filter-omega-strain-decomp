/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cSkeletonBBoxContribution_ContributionPointOffset(char* self) {
    return self + 16;
}

float cSkeletonBBoxContribution_ContributionPointRadius(char* self) {
    return *(float*)(self + 8);
}

int cSkeletonBBoxContribution_BoneIndex(char* self) {
    return *(int*)(self + 0);
}

int cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cSkeletonBBoxContributionPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cSkeletonBBoxContributionPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
