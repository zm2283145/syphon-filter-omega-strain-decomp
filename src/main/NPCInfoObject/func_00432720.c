/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

Word* func_00432720(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00432730(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00432740(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
