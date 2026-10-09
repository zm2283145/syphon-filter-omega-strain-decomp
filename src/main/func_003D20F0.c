/*
 * Matched functions (byte-identical with the retail executable).
 * Container/iterator helpers; original translation unit not identified yet.
 */

#include "types.h"
#include "loose04_types.h"

/* Iterator inequality. */
int func_003D20F0(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* end(): iterator at the tree header. */
void func_003D2110(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
L4Iter* func_003D2120(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

void* func_003D2140(void* self) {
    return self;
}

int func_003D2150(Word* self) {
    return self->value;
}

/* Iterator dereference. */
int* func_003D2160(L4Iter* it) {
    return &it->node->value;
}

Word* func_003D2170(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* begin() of a PtrVec. */
void func_003D2180(Iter* out, PtrVec* v) {
    out->p = v->data;
}
