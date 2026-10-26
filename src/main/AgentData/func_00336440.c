/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector accessors.
 */

#include "types.h"
#include "AgentData_types.h"

int cArray_eRequirementState_Size(ByteVec* v) {
    return v->count;
}

char* cArray_eRequirementState_opIndex(ByteVec* v, int i) {
    return v->data + i;
}
