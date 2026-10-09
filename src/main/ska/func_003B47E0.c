/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

Word* func_003B47E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003B47F0(Iter* out, Tree* t) {
    out->p = &t->header;
}
