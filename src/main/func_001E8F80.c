/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Iter* func_001E8F80(Iter* it) {
    it->p++;
    return it;
}

void func_001E8FA0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
