/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

int* std_vector_imp_charPtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_charPtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_charPtr_1_begin(char* self) {
    return *(int*)(self + 8);
}

void std_tree_pair_cString16N_value_compare_cAllocator_pair_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

void std_tree_pair_cString16N_value_compare_cAllocator_pair_begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

Word* cArray_cSkaNodePtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cSkaNodePtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void std_vector_cSkaNodePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cSkaNodePtr_1_begin(char* self) {
    return *(int*)(self + 8);
}
