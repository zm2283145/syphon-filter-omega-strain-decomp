/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */

#include "types.h"
#include "AgentData_types.h"

/* end() of the registration row vector. */
ObjectiveRow* std_vector_imp_RatingRecord_end(ObjectiveRowVec* v) {
    return v->data + v->count;
}

void std_vector_RatingRecord_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() of the registration row vector. */
ObjectiveRow* std_vector_imp_RatingRecord_begin(ObjectiveRowVec* v) {
    return v->data;
}
