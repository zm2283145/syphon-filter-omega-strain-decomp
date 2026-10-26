/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(char* self) {
    return *(int*)(self + 8);
}
