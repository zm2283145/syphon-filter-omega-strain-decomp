/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "Generator_types.h"

/* Iterator dereference: address of the node value. */
int* cLListIterator_cSafePtr_cGOBJ_opMul(GenListPos* it) {
    return &it->node->value;
}

Word* cLListIterator_cSafePtr_cGOBJ_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cLList_cSafePtr_cGOBJ_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cSafePtr_cGOBJ_ctor_void(void* self) {
    return self;
}
