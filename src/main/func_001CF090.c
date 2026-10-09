/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* func_001CF090(PtrVec* v) {
    return v->data + v->count;
}

void func_001CF0B0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_001CF0C0(PtrVec* v) {
    return v->data;
}

int func_001CF0D0(Word* w) {
    return w->value;
}

void func_001CF0E0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001CF100(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x1D0-byte records. */
void func_001CF110(Elem1D0Iter* out, Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

Word* func_001CF140(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001CF150(Iter* out, PtrVec* v) {
    out->p = v->data;
}
