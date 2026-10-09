/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

Word* func_00432F20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00432F30(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_00432F40(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
