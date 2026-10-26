/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(PtrVec* v) {
    return v->data;
}

float func_001E5260(AnimScalar* self) {
    return self->unk0C;
}

/* Reset the timer from the definition's duration (+0x10). */
void AnimScalar_RestartTimer(AnimScalar* self) {
    self->timer = self->def->duration;
}
