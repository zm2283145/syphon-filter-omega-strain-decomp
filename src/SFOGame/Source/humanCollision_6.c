/*
 * SFOGame/Source/humanCollision: 3 files, 001E11F0-001E1390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E11F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cCollisionEdgePtr_1_dtor)
static inline void merge_flush_func_001E11F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E11F0 */

/* merge_units: begin func_001E12E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int std_vector_cCollisionEdgePtr_push_back(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return std_vector_pod_int_insert(v, data + count, 1, value);
}

Rel* std_vector_cCollisionEdgePtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cArray_cEdgeGroup_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* cArray_cEdgeGroup_Iterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}

/* push_back(value). */
int cArray_cCollisionEdgePtr_PushBackActual(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return std_vector_pod_int_insert(v, data + count, 1, value);
}

/* clear(): count = 0. */
void cArray_cCollisionEdgePtr_Clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_001E12E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E12E0 */

/* merge_units: begin func_001E1390 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
struct It1E1390 { char* p; };
extern "C" {
char* std_vector_imp_cCollisionEdgePtr_1_begin(void* v);
char* std_vector_imp_cCollisionEdgePtr_1_end(void* v);
void std_vector_cCollisionEdgePtr_pointer2iterator(It1E1390* out, void* v, char** p);
#if 0 /* merge_units */
void std_vector_cCollisionEdgePtr_push_back(void* self, char* elem);
#endif /* merge_units */
#define std_vector_cCollisionEdgePtr_push_back(a0, a1) ((void)std_vector_cCollisionEdgePtr_push_back((PtrVec *)(a0), (int)(a1))) /* merge_units */

}
static inline bool It1E1390_eq(char* a, char* b) { return a == b; }
static inline bool It1E1390_ne(char* a, char* b) { return !It1E1390_eq(a, b); }
extern "C" void cEdgeGroup_Append(void* self, void* v)
{
    It1E1390 it;
    It1E1390 end;
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
    for (; It1E1390_ne(p, e); p += 4)
        std_vector_cCollisionEdgePtr_push_back(self, p);
}
#undef std_vector_cCollisionEdgePtr_push_back /* merge_units */
static inline void merge_flush_func_001E1390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1390 */
