/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */

#include "types.h"

Word* func_003A38F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003A3900(Iter* out, PtrVec* v) {
    out->p = v->data;
}
