/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float cSkeletonCenterOfMassContribution_Weight(char* self) {
    return *(float*)(self + 4);
}

/* Address of 464-byte skeleton node i. */
char* cArray_cBone_opIndex_int_2(PtrVec* v, int i) {
    char* data = (char*)v->data;

    return data + i * 464;
}

int cSkeletonCenterOfMassContribution_BoneIndex(char* self) {
    return *(int*)(self + 0);
}

int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cSkeletonCenterOfMassContributionPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cSkeletonCenterOfMassContributionPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int cArray_cBone_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 464-byte nodes. */
Iter16* cArray_cBone_Iterator_opInc(Iter16* it) {
    it->p = it->p + 464;
    return it;
}
