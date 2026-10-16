/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int* value);

/* push_back on a pointer vector. */
int func_0036F510(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
