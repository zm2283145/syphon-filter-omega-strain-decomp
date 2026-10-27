/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector element access.
 */

#include "types.h"
#include "AgentData_types.h"

char* std_vector_eAchievementState_opIndex(ByteVec* v, int i) {
    return v->data + i;
}
