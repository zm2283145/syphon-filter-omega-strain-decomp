/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_init_uint_uintR(PtrVec*, int, int);
extern int std_vector_imp_cObjectId_init(PtrVec*, int, int);

/* Empty vector, then fill through std_vector_imp_cObjectId_init. */
PtrVec* std_vector_cObjectId_ctor_uint_cObjectIdR(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    std_vector_imp_cObjectId_init(v, a1, a2);
    return v;
}

/* Empty vector, then fill through std_vector_pod_int_init_uint_uintR. */
PtrVec* std_vector_cGOBJPtr_ctor_uint_cGOBJPR(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    std_vector_pod_int_init_uint_uintR(v, a1, a2);
    return v;
}
