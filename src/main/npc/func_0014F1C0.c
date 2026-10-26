/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void std_vector_int_end_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_int_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_int_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End pointer of a vector of 8-byte elements. */
int* std_vector_imp_tNodeLink_end_void(PtrVec* v) {
    return v->data + (v->count << 1);
}

void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_tNodeLink_begin_void(PtrVec* v) {
    return v->data;
}
