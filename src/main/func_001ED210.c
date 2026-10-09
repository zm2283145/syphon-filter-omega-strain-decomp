/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

FlagElem16* func_001ED210(FlagElem16Iter* it) {
    return it->p;
}

/* End iterator of an array of 16-byte elements. */
void func_001ED220(FlagElem16Iter* out, Vec16Array* v) {
    out->p = v->data + v->count;
}

void func_001ED240(Iter* out, PtrVec* v) {
    out->p = v->data;
}
