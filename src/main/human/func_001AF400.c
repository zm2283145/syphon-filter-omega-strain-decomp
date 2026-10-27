/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cBone_GetSkeletonCenterOfMassContribution(char* self) {
    return self + 368;
}

int cArray_cBone_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 464-byte nodes. */
void cArray_cBone_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 464;
}

void cArray_cBone_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
