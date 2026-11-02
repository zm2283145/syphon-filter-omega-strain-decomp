/*
 * Libs/SFOLib/Source/GobjMan: 5 files, 0040B920-0040BB70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B920 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cSystemPtr_dtor)
static inline void merge_flush_func_0040B920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B920 */

/* merge_units: begin func_0040BA10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct A40BA10 { char pad[0xC]; unsigned char flag; char pad2[3]; };
struct S40BA10 { int prio; A40BA10 a; A40BA10 b; };
struct V40BA10;
struct It40BA10 { S40BA10** p; };
extern "C" {
void std_vector_cSystemPtr_ctor(A40BA10* a);
int cArrayCapacity_Int(int* kind);
void std_vector_cSystemPtr_reserve(A40BA10* a, int v);
void std_vector_cObjectId_ctor_void(A40BA10* a);
V40BA10* GetPurgeList(void);
void std_vector_cBaseObjListPtr_push_back(V40BA10* v, S40BA10** e);
int cArray_cBaseObjListPtr_Size(V40BA10* v);
void cArray_cBaseObjListPtr_ResizeActual(V40BA10* v, int n, S40BA10* const& fill);
void cArray_cBaseObjListPtr_RBegin(It40BA10* out, V40BA10* v);
#if 0 /* merge_units */
void cArray_cBaseObjListPtr_ReverseIterator_ctor(It40BA10* out, It40BA10* src);
#endif /* merge_units */
Word* cArray_cBaseObjListPtr_ReverseIterator_ctor(Word* dst, Word* src); /* merge_units */
#define cArray_cBaseObjListPtr_ReverseIterator_ctor(a0, a1) ((void)cArray_cBaseObjListPtr_ReverseIterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cBaseObjListPtr_REnd(It40BA10* out, V40BA10* v);
#endif /* merge_units */
struct HolderWord; /* merge_units */
void cArray_cBaseObjListPtr_REnd(Word* result, const HolderWord* source); /* merge_units */
#define cArray_cBaseObjListPtr_REnd(a0, a1) (cArray_cBaseObjListPtr_REnd((Word *)(a0), (const HolderWord *)(a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cBaseObjListPtr_ReverseIterator_opNe(It40BA10* a, It40BA10* b);
#endif /* merge_units */
int cArray_cBaseObjListPtr_ReverseIterator_opNe(Iter* a, Iter* b); /* merge_units */
#define cArray_cBaseObjListPtr_ReverseIterator_opNe(a0, a1) (cArray_cBaseObjListPtr_ReverseIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cBaseObjListPtr_ReverseIterator_opInc(It40BA10* it);
#endif /* merge_units */
Iter* cArray_cBaseObjListPtr_ReverseIterator_opInc(Iter* it); /* merge_units */
#define cArray_cBaseObjListPtr_ReverseIterator_opInc(a0) ((void)cArray_cBaseObjListPtr_ReverseIterator_opInc((Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
S40BA10** cArray_cBaseObjListPtr_ReverseIterator_opMul(It40BA10* it);
#endif /* merge_units */
int* cArray_cBaseObjListPtr_ReverseIterator_opMul(Iter* it); /* merge_units */
#define cArray_cBaseObjListPtr_ReverseIterator_opMul(a0) ((S40BA10 * *)cArray_cBaseObjListPtr_ReverseIterator_opMul((Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
S40BA10** cArray_cBaseObjListPtr_Front(V40BA10* v);
#endif /* merge_units */
int cArray_cBaseObjListPtr_Front(PtrVec* v); /* merge_units */
#define cArray_cBaseObjListPtr_Front(a0) ((S40BA10 * *)cArray_cBaseObjListPtr_Front((PtrVec *)(a0))) /* merge_units */

}
static inline void InitA40BA10(A40BA10* a, int* kind)
{
    std_vector_cSystemPtr_ctor(a);
    std_vector_cSystemPtr_reserve(a, cArrayCapacity_Int(kind));
    a->flag = 0;
}
static inline void InitB40BA10(A40BA10* b)
{
    std_vector_cObjectId_ctor_void(b);
    b->flag = 1;
}
static inline void PushFront40BA10(V40BA10* v, S40BA10** x)
{
    It40BA10 src;
    It40BA10 dst;
    It40BA10 end;
    cArray_cBaseObjListPtr_ResizeActual(v, cArray_cBaseObjListPtr_Size(v) + 1, 0);
    cArray_cBaseObjListPtr_RBegin(&src, v);
    cArray_cBaseObjListPtr_ReverseIterator_ctor(&dst, &src);
    cArray_cBaseObjListPtr_REnd(&end, v);
    if (cArray_cBaseObjListPtr_ReverseIterator_opNe(&src, &end))
        cArray_cBaseObjListPtr_ReverseIterator_opInc(&src);
    while (cArray_cBaseObjListPtr_ReverseIterator_opNe(&src, &end)) {
        *cArray_cBaseObjListPtr_ReverseIterator_opMul(&dst) = *cArray_cBaseObjListPtr_ReverseIterator_opMul(&src);
        cArray_cBaseObjListPtr_ReverseIterator_opInc(&src);
        cArray_cBaseObjListPtr_ReverseIterator_opInc(&dst);
    }
    *cArray_cBaseObjListPtr_Front(v) = *x;
}
extern "C" S40BA10* cBaseObjList_ctor(S40BA10* self, int kind, int prio)
{
    int k = kind;
    InitA40BA10(&self->a, &k);
    InitB40BA10(&self->b);
    self->prio = prio;
    if (prio)
        std_vector_cBaseObjListPtr_push_back(GetPurgeList(), &self);
    else
        PushFront40BA10(GetPurgeList(), &self);
    return self;
}
#undef cArray_cBaseObjListPtr_ReverseIterator_ctor /* merge_units */
#undef cArray_cBaseObjListPtr_REnd /* merge_units */
#undef cArray_cBaseObjListPtr_ReverseIterator_opNe /* merge_units */
#undef cArray_cBaseObjListPtr_ReverseIterator_opInc /* merge_units */
#undef cArray_cBaseObjListPtr_ReverseIterator_opMul /* merge_units */
#undef cArray_cBaseObjListPtr_Front /* merge_units */
static inline void merge_flush_func_0040BA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040BA10 */

/* merge_units: begin func_0040BB70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

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
static inline void merge_flush_func_0040BB70(void) {} /* merge_units */
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
static inline void merge_flush_func_0040BBD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040BBD0 */

/* merge_units: begin func_0040BC00 */
#pragma push /* merge_units */
Word* cArray_cBaseObjListPtr_ReverseIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0040BC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040BC00 */
