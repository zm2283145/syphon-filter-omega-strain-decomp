/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector helper.
 */

#include "types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value) */
int std_vector_cBackpackPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
