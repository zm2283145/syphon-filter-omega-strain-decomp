/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00174000(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_00174010(PtrVec* v) {
    return v->data + v->count;
}

int func_00174030(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_00174050(Iter* it) {
    it->p++;
    return it;
}

Word* func_00174070(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word equality. */
int func_00174080(Word* a, Word* b) {
    return a->value == b->value;
}

int* func_001740A0(Iter* it) {
    return it->p;
}

void func_001740B0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001740D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
