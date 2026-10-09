/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Word* func_00392FD0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00392FE0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00392FF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
