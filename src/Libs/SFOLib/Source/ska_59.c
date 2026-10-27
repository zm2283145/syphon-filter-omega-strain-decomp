/*
 * Libs/SFOLib/Source/ska: 1 file, 003B6690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B6690 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003B6690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B6690 */
