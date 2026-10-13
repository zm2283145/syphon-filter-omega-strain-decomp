/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void EQList_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* EQPos_Copy(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void EQList_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* EQPos_CopyConst(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
