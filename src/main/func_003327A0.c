/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003327A0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_003327C0(Iter* it) {
    it->p++;
    return it;
}

Word* func_003327E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_003327F0(char* self) {
    return *(int*)(self + 0);
}

void func_00332800(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00332820(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_00332830(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00332840(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
