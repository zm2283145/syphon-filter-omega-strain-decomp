/*
 * SFOGame/Source/humanCollision: 3 files, 001E1440-001E1580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cCollisionEdgePtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cCollisionEdgePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cCollisionEdgePtr_1_begin(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_001E1440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1440 */

/* merge_units: begin func_001E1480 */
#pragma push /* merge_units */
#pragma cplusplus on
struct It1E1480 { char* p; };
struct E1E1480 { char pad[0x30]; unsigned char kind; };
extern "C" {
#if 0 /* merge_units */
char* std_vector_imp_cCollisionEdgePtr_1_begin(void* v);
#endif /* merge_units */
#define std_vector_imp_cCollisionEdgePtr_1_begin(a0) ((char *)std_vector_imp_cCollisionEdgePtr_1_begin((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
char* std_vector_imp_cCollisionEdgePtr_1_end(void* v);
#endif /* merge_units */
#define std_vector_imp_cCollisionEdgePtr_1_end(a0) ((char *)std_vector_imp_cCollisionEdgePtr_1_end((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cCollisionEdgePtr_pointer2iterator(It1E1480* out, void* v, char** p);
#endif /* merge_units */
#define std_vector_cCollisionEdgePtr_pointer2iterator(a0, a1, a2) (std_vector_cCollisionEdgePtr_pointer2iterator((Iter *)(a0), (a1), (Iter *)(a2))) /* merge_units */

int cCollisionEdge_CanBeConnected(E1E1480* a, E1E1480* b, float x, float y, float z);
static const float dat_004A0360[2] = { 0.707f, 0.0f };
extern float D_004A0368;
extern float D_004A0370;
}
static inline bool It1E1480_eq(char* a, char* b) { return a == b; }
static inline bool It1E1480_ne(char* a, char* b) { return !It1E1480_eq(a, b); }
extern "C" bool cEdgeGroup_DoesEdgeBelong(void* v, E1E1480* k)
{
    It1E1480 it;
    It1E1480 end;
    char* p;
    char* e;
    {
        char* t = std_vector_imp_cCollisionEdgePtr_1_begin(v);
        std_vector_cCollisionEdgePtr_pointer2iterator(&it, v, &t);
    }
    p = it.p;
    {
        char* t = std_vector_imp_cCollisionEdgePtr_1_end(v);
        std_vector_cCollisionEdgePtr_pointer2iterator(&end, v, &t);
    }
    e = end.p;
    if (It1E1480_ne(p, *(char* volatile*)&end.p)) {
        do {
            E1E1480* x = *(E1E1480**)p;
            if ((x->kind & ~0x80) == (k->kind & ~0x80) && cCollisionEdge_CanBeConnected(x, k, (*(float*)dat_004A0360), D_004A0368, D_004A0370)) return true;
            p += 4;
        } while (It1E1480_ne(p, e));
    }
    return false;
}
#undef std_vector_imp_cCollisionEdgePtr_1_begin /* merge_units */
#undef std_vector_imp_cCollisionEdgePtr_1_end /* merge_units */
#undef std_vector_cCollisionEdgePtr_pointer2iterator /* merge_units */
static inline void merge_flush_func_001E1480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1480 */

/* merge_units: begin func_001E1580 */
#pragma push /* merge_units */
#include "loose00_types.h"

FlagElem16* cArray_cCollisionEdge_ConstIterator_opMul(FlagElem16Iter* it) {
    return it->p;
}

Elem60* cArray_cEdgeGroup_Iterator_opMul(Elem60Iter* it) {
    return it->p;
}

/* End iterator of an array of 16-byte elements. */
void cArray_cEdgeGroup_End_void(FlagElem16Iter* out, Vec16Array* v) {
    out->p = v->data + v->count;
}

void cArray_cEdgeGroup_Begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x60-byte records. */
void cArray_cCollisionEdge_End(Elem60Iter* out, Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

void cArray_cCollisionEdge_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001E1580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1580 */
