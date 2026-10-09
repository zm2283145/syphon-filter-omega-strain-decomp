/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void func_0014F1C0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_0014F1E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014F1F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End pointer of a vector of 8-byte elements. */
int* func_0014F200(PtrVec* v) {
    return v->data + (v->count << 1);
}

void func_0014F220(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_0014F230(PtrVec* v) {
    return v->data;
}
