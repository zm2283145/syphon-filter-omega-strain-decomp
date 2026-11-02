/*
 * SFOGame/Source/humanCollision: 15 files, 001E0E50-001E11F0
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
#if 0 /* merge_units */
extern int cEdgeGroup_dtor(FlagElem16*, int);
#endif /* merge_units */
void* cEdgeGroup_dtor(void* self, short deleteFlag); /* merge_units */
#define cEdgeGroup_dtor(a0, a1) ((int)cEdgeGroup_dtor((void *)(a0), (short)(a1))) /* merge_units */



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
#undef cEdgeGroup_dtor /* merge_units */
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

/* merge_units: begin func_001E0FE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member0_dtor.h"
DEFINE_NESTED_MEMBER0_DTOR(cEdgeGroup_dtor, std_vector_cCollisionEdgePtr_dtor)
static inline void merge_flush_func_001E0FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E0FE0 */

/* merge_units: begin func_001E1040 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cCollisionEdgePtr_dtor)
static inline void merge_flush_func_001E1040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1040 */

/* merge_units: begin func_001E1130 */
#pragma push /* merge_units */
extern int std_vector_imp_cEdgeGroup_insert(Vec16Array* v, FlagElem16* pos, int n, int value);

/* push_back(value) on an array of 16-byte elements. */
int cArray_cEdgeGroup_PushBackActual(Vec16Array* v, int value) {
    int count;
    FlagElem16* data;

    count = v->count;
    data = v->data;
    return std_vector_imp_cEdgeGroup_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001E1130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1130 */

/* merge_units: begin func_001E1150 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj1E;

#if 0 /* merge_units */
extern void std_vector_cCollisionEdgePtr_ctor(Obj1E* self);
#endif /* merge_units */
Rel * std_vector_cCollisionEdgePtr_ctor(); /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cCollisionEdgePtr_push_back(Obj1E* self, int* value);
#endif /* merge_units */
int std_vector_cCollisionEdgePtr_push_back(); /* merge_units */


/* Initializes the object, sets its flag and assigns the given value; returns self. */
Obj1E* cEdgeGroup_ctor_cCollisionEdgeP(Obj1E* self, int value)
{
    std_vector_cCollisionEdgePtr_ctor(self);
    self->flag = 1;
    std_vector_cCollisionEdgePtr_push_back(self, &value);
    return self;
}
static inline void merge_flush_func_001E1150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1150 */

/* merge_units: begin func_001E1190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"
DEFINE_BASE_DTOR_CHAIN(cArray_cCollisionEdgePtr_dtor, std_vector_imp_cCollisionEdgePtr_1_dtor)
static inline void merge_flush_func_001E1190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1190 */

/* merge_units: begin func_001E11F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cCollisionEdgePtr_1_dtor)
static inline void merge_flush_func_001E11F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E11F0 */

/* merge_units: begin func_001E12E0 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
char* std_vector_imp_cCollisionEdgePtr_1_begin(void* v);
#endif /* merge_units */
int* std_vector_imp_cCollisionEdgePtr_1_begin(PtrVec* v); /* merge_units */
#define std_vector_imp_cCollisionEdgePtr_1_begin(a0) ((char *)std_vector_imp_cCollisionEdgePtr_1_begin((PtrVec *)(a0))) /* merge_units */


#if 0 /* merge_units */
char* std_vector_imp_cCollisionEdgePtr_1_end(void* v);
#endif /* merge_units */
int* std_vector_imp_cCollisionEdgePtr_1_end(PtrVec* v); /* merge_units */
#define std_vector_imp_cCollisionEdgePtr_1_end(a0) ((char *)std_vector_imp_cCollisionEdgePtr_1_end((PtrVec *)(a0))) /* merge_units */


#if 0 /* merge_units */
void std_vector_cCollisionEdgePtr_pointer2iterator(It1E1390* out, void* v, char** p);
#endif /* merge_units */
void std_vector_cCollisionEdgePtr_pointer2iterator(Iter* out, void* self, Iter* src); /* merge_units */
#define std_vector_cCollisionEdgePtr_pointer2iterator(a0, a1, a2) (std_vector_cCollisionEdgePtr_pointer2iterator((Iter *)(a0), (a1), (Iter *)(a2))) /* merge_units */


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
#undef std_vector_imp_cCollisionEdgePtr_1_begin /* merge_units */
#undef std_vector_imp_cCollisionEdgePtr_1_end /* merge_units */
#undef std_vector_cCollisionEdgePtr_pointer2iterator /* merge_units */
#undef std_vector_cCollisionEdgePtr_push_back /* merge_units */
static inline void merge_flush_func_001E1390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1390 */

/* merge_units: begin func_001E1440 */
#pragma push /* merge_units */
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
