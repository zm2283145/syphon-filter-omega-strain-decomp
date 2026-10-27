/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

int* cArray_VarDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

/* push_back: inserts one value at the end. */
int std_vector_SubScriptPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

int* std_vector_SubScriptPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int* std_vector_intPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
