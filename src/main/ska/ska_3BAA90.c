/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* back(): address of the last element. */
int* func_003BAA90(PtrVec* v) {
    return v->data + v->count - 1;
}
