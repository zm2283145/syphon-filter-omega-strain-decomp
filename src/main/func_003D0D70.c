/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_003D0E40(void* self, int a1, int first, int a2, float f0, float f1);

void func_003D0D70(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003D0D80(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D0D90(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_003D0DA0(Word* self, int value) {
    self->value = value;
    return self;
}

Word* func_003D0DB0(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_003D0DC0(char* self) {
    return self + 4;
}

/* Forwards to func_003D0E40 with the object's first word inserted as the third argument. */
int func_003D0DD0(Word* self, int a1, int a2, float f0, float f1) {
    return func_003D0E40(self, a1, self->value, a2, f0, f1);
}
