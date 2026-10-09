/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */

#include "types.h"
#include "AgentData_types.h"

void* func_00330820(char* self) {
    return self + 8;
}

int func_00330830(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* ++it over ObjectiveRow entries. */
ObjectiveRow** func_00330850(ObjectiveRow** it) {
    *it = *it + 1;
    return it;
}
