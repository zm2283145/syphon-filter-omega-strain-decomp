/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern int std_vector_pod_int_reserve(int a0, int a1);
extern OwnedVec* std_vector_imp_cAnimatorPtr_1_ctor(OwnedVec* v);

/* Clears the three vector words. */
OwnedVec* std_vector_cKeyframe_cXyz_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int cArray_cAnimatorPtr_ReserveActual(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

/* Reads one word from a stream cursor. */
int** cStreamingBuffer_opShr(int** cursor, int* out) {
    *out = **cursor;
    *cursor = *cursor + 1;
    return cursor;
}

OwnedVec* cArray_cAnimatorPtr_ctor(OwnedVec* v) {
    std_vector_imp_cAnimatorPtr_1_ctor(v);
    v->unk0C = 1;
    return v;
}
