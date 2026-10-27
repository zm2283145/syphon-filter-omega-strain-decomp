/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int* value);

/* push_back on a pointer vector. */
int std_vector_cXformNodePtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
