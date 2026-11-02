/*
 * Libs/SFOLib/Source/keyframe: 11 files, 003FCC50-003FD0A0
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
#if 0 /* merge_units */
void std_vector_cAnimatorPtr_end_void(Word* out, PtrVec* v);
#endif /* merge_units */
void std_vector_cAnimatorPtr_end_void(Iter* out, PtrVec* v); /* merge_units */
#define std_vector_cAnimatorPtr_end_void(a0, a1) (std_vector_cAnimatorPtr_end_void((Iter *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Word* out, PtrVec* self, Word* src);
#endif /* merge_units */
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Iter* out, void* self, Iter* src); /* merge_units */
#define std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(a0, a1, a2) (std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */

int std_vector_imp_cAnimatorPtr_1_begin_void(PtrVec* v);
void cAnimator_SetFrame(void* item, float t);
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
        cAnimator_SetFrame(*p, t);
    }
}
#undef std_vector_cAnimatorPtr_end_void /* merge_units */
#undef std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR /* merge_units */
static inline void merge_flush_func_003FCE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCE90 */

/* merge_units: begin keyframe_3FCF60 */
#pragma push /* merge_units */
Word* cArray_cAnimatorPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cAnimatorPtr_end_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cAnimatorPtr_1_begin_void(PtrVec* v) {
    return (int)v->data;
}
static inline void merge_flush_keyframe_3FCF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end keyframe_3FCF60 */

/* merge_units: begin func_003FCFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
class A5_FCFB0_Item {
public:
    virtual void v0();
    virtual float Get();
};
struct A5_FCFB0_It { A5_FCFB0_Item** p; };
struct A5_FCFB0_Self { char pad[0x18]; char list[1]; };
#if 0 /* merge_units */
extern "C" int std_vector_imp_cAnimatorPtr_1_begin_void_2(void* c);
#endif /* merge_units */
extern "C" int std_vector_imp_cAnimatorPtr_1_begin_void_2(PtrVec* v); /* merge_units */
#define std_vector_imp_cAnimatorPtr_1_begin_void_2(a0) (std_vector_imp_cAnimatorPtr_1_begin_void_2((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(A5_FCFB0_It* out, void* c, int* k);
#endif /* merge_units */
extern "C" void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(Iter* out, void* self, Iter* src); /* merge_units */
#define std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(a0, a1, a2) (std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2((Iter *)(a0), (a1), (Iter *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern "C" void std_vector_cAnimatorPtr_end_void_2(A5_FCFB0_It* out, void* c);
#endif /* merge_units */
extern "C" void std_vector_cAnimatorPtr_end_void_2(Iter* out, PtrVec* v); /* merge_units */
#define std_vector_cAnimatorPtr_end_void_2(a0, a1) (std_vector_cAnimatorPtr_end_void_2((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cArray_cAnimatorPtr_ConstIterator_ctor(A5_FCFB0_It* out, A5_FCFB0_It* in);
#endif /* merge_units */
extern "C" Word* cArray_cAnimatorPtr_ConstIterator_ctor(Word* dst, Word* src); /* merge_units */
#define cArray_cAnimatorPtr_ConstIterator_ctor(a0, a1) ((void)cArray_cAnimatorPtr_ConstIterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


inline bool A5_FCFB0_eq(A5_FCFB0_Item** a, A5_FCFB0_Item** b) { return a == b; }
inline bool A5_FCFB0_ne(A5_FCFB0_Item** a, A5_FCFB0_Item** b) { return !A5_FCFB0_eq(a, b); }
inline A5_FCFB0_Item** A5_FCFB0_end(A5_FCFB0_It* r, void* c) {
    A5_FCFB0_It e;
    std_vector_cAnimatorPtr_end_void_2(&e, c);
    cArray_cAnimatorPtr_ConstIterator_ctor(r, &e);
    return r->p;
}

extern "C" float cKfAnimationContainer_NumFrames(A5_FCFB0_Self* self) {
    A5_FCFB0_It r;
    A5_FCFB0_It it;
    int k;
    float best = 0.0f;
    A5_FCFB0_Item** p;
    k = std_vector_imp_cAnimatorPtr_1_begin_void_2(self->list);
    std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(&it, self->list, &k);
    for (p = it.p; A5_FCFB0_ne(p, A5_FCFB0_end(&r, self->list)); p++) {
        float f = (*p)->Get();
        if (!(f <= best)) best = f;
    }
    return best;
}
#undef std_vector_imp_cAnimatorPtr_1_begin_void_2 /* merge_units */
#undef std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2 /* merge_units */
#undef std_vector_cAnimatorPtr_end_void_2 /* merge_units */
#undef cArray_cAnimatorPtr_ConstIterator_ctor /* merge_units */
static inline void merge_flush_func_003FCFB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FCFB0 */

/* merge_units: begin func_003FD0A0 */
#pragma push /* merge_units */
Word* cArray_cAnimatorPtr_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cAnimatorPtr_end_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cAnimatorPtr_1_begin_void_2(PtrVec* v) {
    return (int)v->data;
}
static inline void merge_flush_func_003FD0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FD0A0 */

/* merge_units: begin func_003FD0F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
extern char D_004BE3B0[];
extern char D_004E0800[];
extern char D_004E0820[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
#if 0 /* merge_units */
void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cAnimatorPtr_end_void(Word* out, PtrVec* v);
#endif /* merge_units */
#define std_vector_cAnimatorPtr_end_void(a0, a1) (std_vector_cAnimatorPtr_end_void((Iter *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Word* out, PtrVec* self, Word* src);
#endif /* merge_units */
#define std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(a0, a1, a2) (std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */

void std_vector_cAnimatorPtr_dtor(PtrVec* v, short deleteFlag);
}

struct Obj { virtual ~Obj(); };
#pragma bool off

#pragma bool reset


extern "C" Holder* cKfAnimationContainer_dtor(Holder* self, short deleteFlag)
{
    if (self) {
        Obj* o;
        Word end;
        Word it;
        Obj** p;
        self->vtable = D_004E0820;
        GetBegin(&it, &self->items);
        for (p = (Obj**)it.value; GetEnd(&end, &self->items), Ne((int)p, end.value); p++) {
            o = *p;
            {
                AllocGuard guard;
                o->~Obj();
                cMemMan_Deallocate(0, o, D_004BE3B0, 0xF);
            }
        }
        if (&self->items)
            std_vector_cAnimatorPtr_dtor(&self->items, -1);
        if (self)
            self->vtable = D_004E0800;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
#undef std_vector_cAnimatorPtr_end_void /* merge_units */
#undef std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR /* merge_units */
static inline void merge_flush_func_003FD0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FD0F0 */
