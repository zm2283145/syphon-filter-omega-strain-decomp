/*
 * main/player: 3 files, 0040BB70-0040BC00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040BB70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int cArray_cBaseObjListPtr_Front(PtrVec* v) {
    return (int)v->data;
}

/* Address of the previous word (reverse-iterator dereference). */
int* cArray_cBaseObjListPtr_ReverseIterator_opMul(Iter* it) {
    return it->p - 1;
}

/* Steps the pointer back one word. */
Iter* cArray_cBaseObjListPtr_ReverseIterator_opInc(Iter* it) {
    it->p = it->p - 1;
    return it;
}

int cArray_cBaseObjListPtr_ReverseIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BB70 */

/* merge_units: begin func_0040BBD0 */
#pragma push /* merge_units */
typedef struct HolderWord {
    char pad00[8];
    int value;
} HolderWord;

/* Copy the holder's word through the two value-object temporaries. */
void cArray_cBaseObjListPtr_REnd(Word* result, const HolderWord* source)
{
    Word first;
    Word second;
    first.value = source->value;
    second = first;
    result->value = second.value;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BBD0 */

/* merge_units: begin func_0040BC00 */
#pragma push /* merge_units */
Word* cArray_cBaseObjListPtr_ReverseIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BC00 */
