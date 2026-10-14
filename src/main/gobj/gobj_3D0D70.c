/*
 * main/gobj: 2 files, 003D0D70-003D0DE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D0D70 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_003D0D70 */

/* merge_units: begin func_003D0DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_003D0DE0, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D0DE0 */
