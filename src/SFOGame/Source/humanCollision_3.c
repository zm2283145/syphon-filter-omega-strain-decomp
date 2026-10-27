/*
 * SFOGame/Source/humanCollision: 4 files, 001E0E50-001E0F80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E0E50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cBitArray_5_dtor)
static inline void merge_flush_func_001E0E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E0E50 */

/* merge_units: begin func_001E0EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_opAssign(void*, void*);
extern int std_vector_imp_cEdgeGroup_pop_back(Vec16Array*);
extern int cEdgeGroup_dtor(FlagElem16*, int);

/* End pointer of an array of 0x60-byte records. */
Elem60* std_vector_imp_cCollisionEdge_end(Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void std_vector_cCollisionEdge_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem60* std_vector_imp_cCollisionEdge_begin(Vec60Array* v) {
    return v->data;
}

int cArray_cEdgeGroup_PopBack(Vec16Array* v) {
    return std_vector_imp_cEdgeGroup_pop_back(v);
}

/* Pop the last 16-byte element and destroy it. */
int std_vector_imp_cEdgeGroup_pop_back(Vec16Array* v) {
    int count;
    FlagElem16* data;

    count = v->count;
    v->count = count + -1;
    data = v->data;
    return cEdgeGroup_dtor(data + (count + -1), -1);
}

/* Copy-construct: base copy then the flag byte at +0x0C. */
FlagElem16* cEdgeGroup_opAssign(FlagElem16* d, FlagElem16* s) {
    unsigned char flag;

    std_vector_pod_int_opAssign(d, s);
    flag = s->unk0C;
    d->unk0C = flag;
    return d;
}

/* Last element of a 16-byte array. */
FlagElem16* cArray_cEdgeGroup_Back(Vec16Array* v) {
    return (v->data + v->count) + -1;
}
static inline void merge_flush_func_001E0EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E0EA0 */

/* merge_units: begin func_001E0F70 */
#pragma push /* merge_units */
typedef struct { int unk0; void* p; } S;
/* Returns whether the second field is null. */
int cArray_cCollisionEdgePtr_Empty(S* s) { return s->p == 0; }
static inline void merge_flush_func_001E0F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E0F70 */

/* merge_units: begin func_001E0F80 */
#pragma push /* merge_units */
/* Address of element index of a 16-byte element array. */
FlagElem16* cArray_cEdgeGroup_opIndex(Vec16Array* v, int index) {
    return v->data + index;
}

int cArray_cEdgeGroup_Size(Vec16Array* v) {
    return v->count;
}

int cArray_cCollisionEdge_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 0x60-byte records. */
Elem60Iter* cArray_cCollisionEdge_ConstIterator_opInc(Elem60Iter* it) {
    it->p = it->p + 1;
    return it;
}
static inline void merge_flush_func_001E0F80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E0F80 */
