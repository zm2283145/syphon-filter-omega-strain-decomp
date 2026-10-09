/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector element access.
 */

#include "types.h"
#include "AgentData_types.h"

char* func_00333790(ByteVec* v, int i) {
    return v->data + i;
}
