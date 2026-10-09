/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0045C960(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_0045C980(Iter* it) {
    it->p++;
    return it;
}

Word* func_0045C9A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0045C9B0(char* self) {
    return *(int*)(self + 0);
}

void func_0045C9C0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_0045C9E0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_0045C9F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0045CA00(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
