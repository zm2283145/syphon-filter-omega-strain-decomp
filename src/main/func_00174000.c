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
