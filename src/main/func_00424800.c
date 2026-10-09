/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int value);

/* push_back. */
int func_00424800(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
