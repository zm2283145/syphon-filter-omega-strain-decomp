/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int PtrVec_Insert(PtrVec*, int*, int, int);

/* push_back: insert one value at end(). */
int std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return PtrVec_Insert(v, data + count, 1, value);
}
