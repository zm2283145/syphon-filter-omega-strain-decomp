/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00273180(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00273190(void* self) {
    return self;
}

Word* func_002731A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731B0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002731C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002731E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
