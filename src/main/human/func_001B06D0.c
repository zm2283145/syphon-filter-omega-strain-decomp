/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int);

/* push_back: insert one value at end(). */
int std_vector_cSkeletonBBoxContributionPtr_push_back(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
