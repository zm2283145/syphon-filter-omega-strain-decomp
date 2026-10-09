/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_003B6690(PtrVec* v) {
    return v->data + v->count;
}

void func_003B66B0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_003B66C0(char* self) {
    return *(int*)(self + 8);
}

void func_003B66D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_003B66E0(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

Word* func_003B66F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003B6700(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_003B6720(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_003B6730(char* self) {
    return *(int*)(self + 8);
}
