/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int* std_vector_imp_cObjectId_begin(PtrVec* v) {
    return v->data;
}
