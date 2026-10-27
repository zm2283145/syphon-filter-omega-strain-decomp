/*
 * Libs/SFOLib/Source/keyframe: 7 files, 003FCC50-003FCE90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FCC50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_tree_pair_int_value_compare_node_alloc_void(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_3(void) {
}

void* std_tree_pair_int_value_compare_alloc_void(void* self) {
    return self;
}

Map* func_003FCC80(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_2(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
static inline void merge_flush_func_003FCC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCC50 */

/* merge_units: begin func_003FCCC0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TCCC0;
extern void std_tree_pair_int_value_compare_destroy_nodeP_2(TCCC0* t, void* n);
extern void operator_delete(void* p);
TCCC0* std_tree_pair_int_value_compare_dtor_void(TCCC0* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_destroy_nodeP_2(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
static inline void merge_flush_func_003FCCC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCCC0 */

/* merge_units: begin func_003FCD20 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TCD20;
extern void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(TCD20* t, void* n);
TCD20* std_tree_pair_int_value_compare_cAllocator_pair_dtor(TCD20* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
static inline void merge_flush_func_003FCD20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCD20 */

/* merge_units: begin func_003FCD80 */
#pragma push /* merge_units */
int cNetObj_tPingInfo_ctor(int a0) {
    int a1, v0, v1;
    int cond;

    *(char*)((char*)a0 + 20) = 0;
    a1 = 0;
    *(int*)((char*)a0 + 24) = 0;
    v1 = a0;
    *(short*)((char*)a0 + 148) = 0;
L003FCD98:;
    *(int*)((char*)v1 + 28) = 0;
    *(int*)((char*)v1 + 32) = 0;
    a1 = a1 + 6;
    *(int*)((char*)v1 + 36) = 0;
    v0 = a1 < 30;
    *(int*)((char*)v1 + 40) = 0;
    *(int*)((char*)v1 + 44) = 0;
    *(int*)((char*)v1 + 48) = 0;
    cond = v0 != 0;
    v1 = v1 + 24;
    if (cond) goto L003FCD98;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_003FCD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCD80 */

/* merge_units: begin func_003FCDD0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_dtor_void(void* self, short del);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_dtor_void(a0, a1) ((void)std_tree_pair_int_value_compare_dtor_void((TCCC0 *)(a0), (a1))) /* merge_units */

void* cAssocArray_int_netSystemField_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_tree_pair_int_value_compare_dtor_void(self, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_tree_pair_int_value_compare_dtor_void /* merge_units */
static inline void merge_flush_func_003FCDD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCDD0 */

/* merge_units: begin func_003FCE30 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_cAllocator_pair_dtor(void* self, short del);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_cAllocator_pair_dtor(a0, a1) ((void)std_tree_pair_int_value_compare_cAllocator_pair_dtor((TCD20 *)(a0), (a1))) /* merge_units */

void* cAssocArray_int_cSafePtr_cGOBJ_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_tree_pair_int_value_compare_cAllocator_pair_dtor(self, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_tree_pair_int_value_compare_cAllocator_pair_dtor /* merge_units */
static inline void merge_flush_func_003FCE30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCE30 */

/* merge_units: begin func_003FCE90 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
Word* cArray_cAnimatorPtr_Iterator_ctor(Word* dst, Word* src);
void std_vector_cAnimatorPtr_end_void(Word* out, PtrVec* v);
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Word* out, PtrVec* self, Word* src);
int std_vector_imp_cAnimatorPtr_1_begin_void(PtrVec* v);
void viBufGetTs(void* item, float t);
}

#pragma bool off
static inline int Ne(int a, int b) { return !(a == b); }
#pragma bool reset
static inline void GetEnd(Word* out, PtrVec* v) { Word e; std_vector_cAnimatorPtr_end_void(&e, v); cArray_cAnimatorPtr_Iterator_ctor(out, &e); }
static inline void GetBegin(Word* out, PtrVec* v) { Word b; b.value = std_vector_imp_cAnimatorPtr_1_begin_void(v); std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(out, v, &b); }
struct Holder {
    char* vtable;
    char pad[0x14];
    PtrVec items;
};

extern "C" void cKfAnimationContainer_Update(Holder* self, float t)
{
    Word end;
    Word it;
    void** p;
    GetBegin(&it, &self->items);
    for (p = (void**)it.value; GetEnd(&end, &self->items), Ne((int)p, end.value); p++) {
        viBufGetTs(*p, t);
    }
}
static inline void merge_flush_func_003FCE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCE90 */
