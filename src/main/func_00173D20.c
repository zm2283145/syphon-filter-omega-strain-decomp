/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_init_uint_uintR(PtrVec*, int, ValFlag*);

/* Empty vector, then fill through std_vector_pod_int_init_uint_uintR with a {value, 0} argument. */
PtrVec* std_vector_int_ctor_int_int(PtrVec* v, int a1, int value) {
    ValFlag arg;

    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    arg.value = value;
    arg.flag = 0;
    std_vector_pod_int_init_uint_uintR(v, a1, &arg);
    return v;
}
