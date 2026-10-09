/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int func_003D8A10(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
