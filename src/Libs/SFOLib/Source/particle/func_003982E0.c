/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector push_back helpers.
 */

#include "types.h"
#include "particle_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int std_vector_cEffectRequestPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* push_back on a pointer vector. */
int cArray_intPtr_PushBackActual(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
