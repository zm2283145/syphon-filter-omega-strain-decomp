/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* std_list_cNPCPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}

Word* std_list_cActiveListItemPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* cLListIterator_cNPCPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cNPCPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cNPCPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR(Word* a, Word* b) {
    return (0U < (unsigned int)(a->value ^ b->value));
}

void cLList_cNPCPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Linked-list iterator increment: follow node->next (+4). */
Iter* cLListIterator_cNPCPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}

/* Address of the node payload (+8). */
int* cLListIterator_cNPCPtr_opMul(Iter* it) {
    return it->p + 2;
}

float* cLListIterator_cNPCPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_cNPCPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cNPCPtr_ctor_void(void* self) {
    return self;
}
