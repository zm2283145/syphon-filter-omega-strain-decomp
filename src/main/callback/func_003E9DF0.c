/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cCBDataPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* EQPos_Copy(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cCBDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* EQPos_CopyConst(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
