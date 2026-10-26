/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int PtrVec_Insert(SkaVec* v, char* pos, int n, int value);

/* Append one pointer at the end of the array. */
int std_vector_cSkaNodePtr_push_back(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return PtrVec_Insert(v, data + (count << 2), 1, value);
}

Word* cAssocArray_cString16N_3_int_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString16N_3_int_cAllocator_pair_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}
