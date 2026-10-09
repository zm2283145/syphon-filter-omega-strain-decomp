/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"

Word* func_003EC690(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003EC6A0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003EC6B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
