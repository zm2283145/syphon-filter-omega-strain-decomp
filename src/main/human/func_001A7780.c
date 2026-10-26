/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* Ptr_IdentityCast(void* self) {
    return self;
}

int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cMatrix_GetYAxis(char* self) {
    return self + 8;
}
