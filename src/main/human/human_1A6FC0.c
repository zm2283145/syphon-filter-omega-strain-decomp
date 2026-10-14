/*
 * main/human: range (3 files, 001A6FC0-001A7040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001A6FC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_001A6FC0(Iter* a, Iter* b) {
    return a->p == b->p;
}

int func_001A6FE0(char* self) {
    return *(int*)(self + 0);
}

void func_001A6FF0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_001A7010(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001A7020(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A6FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A6FC0 */

/* merge_units: begin func_001A7030 */
#pragma push /* merge_units */
typedef struct { int unk0; void* p; } S;
/* Returns whether the second field is null. */
int func_001A7030(S* s) { return s->p == 0; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7030 */

/* merge_units: begin func_001A7040 */
#pragma push /* merge_units */
int* func_001A7040(PtrVec* v) {
    return v->data + v->count;
}

int func_001A7060(char* self) {
    return *(int*)(self + 8);
}

void* Root_IdentityAccessor(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7040 */
