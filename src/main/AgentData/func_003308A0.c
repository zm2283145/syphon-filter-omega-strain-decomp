/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */

#include "types.h"
#include "AgentData_types.h"

ObjectiveRow* func_003308A0(ObjectiveRow** it) {
    return *it;
}

/* out = end() of the registration row vector. */
void func_003308B0(ObjectiveRow** out, ObjectiveRowVec* v) {
    *out = v->data + v->count;
}

void func_003308D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
