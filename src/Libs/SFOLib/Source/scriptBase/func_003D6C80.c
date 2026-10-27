/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_FieldDefPtr_opIndex_uint(PtrVec* v, int i) {
    return v->data + i;
}
