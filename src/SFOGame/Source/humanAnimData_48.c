/*
 * SFOGame/Source/humanAnimData: 2 files, 001F4440-001F4470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F4440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

FloatPair* cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

FloatPair* cSkaBlendSequenceExtents_ctor_float_float(FloatPair* self, float a, float b) {
    self->a = a;
    self->b = b;
    return self;
}
static inline void merge_flush_func_001F4440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4440 */

/* merge_units: begin func_001F4470 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void cLList_cSkaBlendSequenceItemPtr_ctor(void* obj);

/* Runs cLList_cSkaBlendSequenceItemPtr_ctor on obj and returns obj. */
void* cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void* obj) {
    cLList_cSkaBlendSequenceItemPtr_ctor(obj);
    return obj;
}

#pragma pop
static inline void merge_flush_func_001F4470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4470 */
