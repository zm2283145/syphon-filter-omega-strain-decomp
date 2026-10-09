/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"

void func_00232EE0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00232EF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00232F00(Iter* out, PtrVec* v) {
    out->p = v->data;
}
