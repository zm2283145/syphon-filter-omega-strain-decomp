/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int PtrVec_Insert(SkaVec* v, char* pos, int n, int value);

/* Append one pointer at the end of the array. */
int func_003B4960(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return PtrVec_Insert(v, data + (count << 2), 1, value);
}

Word* func_003B4980(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003B4990(Iter* out, Tree* t) {
    out->p = &t->header;
}
