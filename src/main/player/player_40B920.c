/*
 * main/player: 2 files, 0040B920-0040BA10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B920 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cSystemPtr_dtor)
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
V40BA10* GobjScope_GetList(void);
void PtrVec_PushBack_40BC70(V40BA10* v, S40BA10** e);
int cArray_cBaseObjListPtr_Size(V40BA10* v);
void cArray_cBaseObjListPtr_ResizeActual(V40BA10* v, int n, S40BA10* const& fill);
void cArray_cBaseObjListPtr_RBegin(It40BA10* out, V40BA10* v);
void cArray_cBaseObjListPtr_ReverseIterator_ctor(It40BA10* out, It40BA10* src);
void cArray_cBaseObjListPtr_REnd(It40BA10* out, V40BA10* v);
int cArray_cBaseObjListPtr_ReverseIterator_opNe(It40BA10* a, It40BA10* b);
void cArray_cBaseObjListPtr_ReverseIterator_opInc(It40BA10* it);
S40BA10** cArray_cBaseObjListPtr_ReverseIterator_opMul(It40BA10* it);
S40BA10** cArray_cBaseObjListPtr_Front(V40BA10* v);
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
extern "C" S40BA10* GobjScopeBase_Ctor(S40BA10* self, int kind, int prio)
{
    int k = kind;
    InitA40BA10(&self->a, &k);
    InitB40BA10(&self->b);
    self->prio = prio;
    if (prio)
        PtrVec_PushBack_40BC70(GobjScope_GetList(), &self);
    else
        PushFront40BA10(GobjScope_GetList(), &self);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BA10 */
