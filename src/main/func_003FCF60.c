/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003FCF60(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003FCF70(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_003FCF90(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_003FCFA0(char* self) {
    return *(int*)(self + 8);
}
