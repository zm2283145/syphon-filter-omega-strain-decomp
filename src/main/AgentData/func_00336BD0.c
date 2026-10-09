/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector helper.
 */

#include "types.h"
#include "AgentData_types.h"

extern int func_003371B0(ByteVec* v, char* pos, int n, int value);

/* push_back(value) */
int func_00336BD0(ByteVec* v, int value) {
    return func_003371B0(v, v->data + v->count, 1, value);
}
