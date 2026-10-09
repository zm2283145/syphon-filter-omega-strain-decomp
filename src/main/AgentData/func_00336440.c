/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector accessors.
 */

#include "types.h"
#include "AgentData_types.h"

int func_00336440(ByteVec* v) {
    return v->count;
}

char* func_00336450(ByteVec* v, int i) {
    return v->data + i;
}
