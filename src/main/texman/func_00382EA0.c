/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

Word* func_00382EA0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00382EB0(Iter* out, Tree* t) {
    out->p = &t->header;
}

TexListIter* func_00382EC0(TexListIter* it, TexListNode* node) {
    it->node = node;
    return it;
}
