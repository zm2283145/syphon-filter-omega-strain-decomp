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
DEFINE_BUF_HOLDER_DTOR(func_0040B920)
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
void func_0040BCA0(A40BA10* a);
int func_001361D0(int* kind);
void func_0040BC90(A40BA10* a, int v);
void func_001C29F0(A40BA10* a);
V40BA10* GobjScope_GetList(void);
void PtrVec_PushBack_40BC70(V40BA10* v, S40BA10** e);
int func_0040BC60(V40BA10* v);
void func_0040BC50(V40BA10* v, int n, S40BA10* const& fill);
void func_0040BC10(It40BA10* out, V40BA10* v);
void func_0040BC00(It40BA10* out, It40BA10* src);
void func_0040BBD0(It40BA10* out, V40BA10* v);
int func_0040BBB0(It40BA10* a, It40BA10* b);
void func_0040BB90(It40BA10* it);
S40BA10** func_0040BB80(It40BA10* it);
S40BA10** func_0040BB70(V40BA10* v);
}
static inline void InitA40BA10(A40BA10* a, int* kind)
{
    func_0040BCA0(a);
    func_0040BC90(a, func_001361D0(kind));
    a->flag = 0;
}
static inline void InitB40BA10(A40BA10* b)
{
    func_001C29F0(b);
    b->flag = 1;
}
static inline void PushFront40BA10(V40BA10* v, S40BA10** x)
{
    It40BA10 src;
    It40BA10 dst;
    It40BA10 end;
    func_0040BC50(v, func_0040BC60(v) + 1, 0);
    func_0040BC10(&src, v);
    func_0040BC00(&dst, &src);
    func_0040BBD0(&end, v);
    if (func_0040BBB0(&src, &end))
        func_0040BB90(&src);
    while (func_0040BBB0(&src, &end)) {
        *func_0040BB80(&dst) = *func_0040BB80(&src);
        func_0040BB90(&src);
        func_0040BB90(&dst);
    }
    *func_0040BB70(v) = *x;
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
