/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int std_vector_cCollisionEdgePtr_push_back(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

Rel* std_vector_cCollisionEdgePtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cArray_cEdgeGroup_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* cArray_cEdgeGroup_Iterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}

/* push_back(value). */
int cArray_cCollisionEdgePtr_PushBackActual(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

/* clear(): count = 0. */
void cArray_cCollisionEdgePtr_Clear(PtrVec* v) {
    v->count = 0;
}
