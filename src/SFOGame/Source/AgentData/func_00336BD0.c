/*
 * Matched functions (byte-identical with the retail executable).
 * Byte-vector helper.
 */

#include "types.h"
#include "AgentData_types.h"

extern int std_vector_pod_eAchievementState_insert(ByteVec* v, char* pos, int n, int value);

/* push_back(value) */
int std_vector_eAchievementState_push_back(ByteVec* v, int value) {
    return std_vector_pod_eAchievementState_insert(v, v->data + v->count, 1, value);
}
