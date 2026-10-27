/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentInfo_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00363E60(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
