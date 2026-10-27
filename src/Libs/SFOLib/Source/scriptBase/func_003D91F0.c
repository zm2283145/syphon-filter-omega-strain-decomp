/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);
extern OwnedVec* std_vector_imp_EnumField_ctor(OwnedVec* v);

/* push_back: inserts one value at the end. */
int std_vector_EnumDefPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

OwnedVec* cArray_EnumField_ctor(OwnedVec* v) {
    std_vector_imp_EnumField_ctor(v);
    v->unk0C = 1;
    return v;
}
