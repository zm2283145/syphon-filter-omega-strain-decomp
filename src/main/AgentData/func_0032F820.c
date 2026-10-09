/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */

#include "types.h"
#include "AgentData_types.h"

/* end() of the registration row vector. */
ObjectiveRow* func_0032F820(ObjectiveRowVec* v) {
    return v->data + v->count;
}

void func_0032F840(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() of the registration row vector. */
ObjectiveRow* func_0032F850(ObjectiveRowVec* v) {
    return v->data;
}
