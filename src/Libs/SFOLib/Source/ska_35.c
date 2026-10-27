/*
 * Libs/SFOLib/Source/ska: 3 files, 003B1710-003B1770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B1710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Iterator equality. */
int cSkaPlaybackItem_HasSameAnimation(Iter* a, Iter* b) {
    return a->p == b->p;
}

void* AnimBlend_GetGroupCollection(char* self) {
    return self + 232;
}
static inline void merge_flush_func_003B1710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1710 */

/* merge_units: begin func_003B1740 */
#pragma push /* merge_units */
#include "types.h"
typedef struct AC_3B1740 { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B1740;
/* Initialises an animation contribution record and returns it. */
#pragma peephole off
AC_3B1740* cSkaPlaybackItem_ctor(AC_3B1740* self, int id, float weight, Vec4* v) {
    self->id = id;
    self->weight = weight;
    self->active = 1;
    self->v = *v;
    return self;
}
#pragma peephole reset
static inline void merge_flush_func_003B1740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1740 */

/* merge_units: begin func_003B1770 */
#pragma push /* merge_units */
void** PtrStack_Top(PtrStack* s) {
    return &s->items[s->count - 1];
}

int AnimContext_GetCount(char* self) {
    return *(int*)(self + 0);
}

float cSkaSliderValue_opCast_float(char* self) {
    return *(float*)(self + 8);
}

/* Address of element i in an array of 60-byte elements. */
char* cArray_cSkaSliderValue_opIndex(SkaVec* v, int i) {
    return v->data + i * 60;
}
static inline void merge_flush_func_003B1770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1770 */
