/*
 * SFOGame/Source/humanCollision: 4 files, 001E8F60-001E9090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E8F60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Word equality. */
int func_001E8F60(Word* a, Word* b) {
    return a->value == b->value;
}

Iter* func_001E8F80(Iter* it) {
    it->p++;
    return it;
}

void std_vector_cTreeNode_cSkaSystemPtrPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_001E8FC0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001E8FD0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001E8F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8F60 */

/* merge_units: begin func_001E8FE0 */
#pragma push /* merge_units */
/* Returns whether the word at +4 is zero. */
int func_001E8FE0(int* self)
{
    return self[1] == 0;
}
static inline void merge_flush_func_001E8FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8FE0 */

/* merge_units: begin func_001E8FF0 */
#pragma push /* merge_units */
int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001E9010(Iter* it) {
    it->p++;
    return it;
}

int func_001E9030(Word* w) {
    return w->value;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001E9060(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int cTreeNode_cSkaSystemPtr_HasChildren(Node* n) {
    return !(n->count == 0);
}
static inline void merge_flush_func_001E8FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8FF0 */

/* merge_units: begin func_001E9090 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
#if 0 /* merge_units */
extern int cTreeNode_cSkaSystemPtr_HasChildren(RNode* n);
#endif /* merge_units */
#define cTreeNode_cSkaSystemPtr_HasChildren(a0) (cTreeNode_cSkaSystemPtr_HasChildren((Node *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(RIt* a, RIt* b);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(a0, a1) (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern RIt* func_001E9010(RIt* it);
#endif /* merge_units */
#define func_001E9010(a0) ((RIt *)func_001E9010((Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern RNode** func_001E9030(RIt* w);
#endif /* merge_units */
#define func_001E9030(a0) ((RNode * *)func_001E9030((Word *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(RIt* out, RVec* v);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(a0, a1) (cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_001E9060(RIt* out, RVec* v);
#endif /* merge_units */
#define func_001E9060(a0, a1) (func_001E9060((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

extern RNode** func_001E9250(RVec* v);
extern void func_001E9270(RIt* out, RVec* self, RIt* src);
extern RNode** func_001E9280(RVec* v);
unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t);
}

static inline bool Check(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (cTreeNode_cSkaSystemPtr_HasChildren(n)) {
        bool found = 0;
        RIt it, end;
        func_001E9060(&it, &n->children);
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(&end, &n->children);
        while (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(&it, &end)) {
            if (cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(*func_001E9030(&it), t)) { found = 1; break; }
            func_001E9010(&it);
        }
        return found;
    }
    return 0;
}

static inline bool HasKids(RVec* v) { return !(v->count == 0); }
static inline void Begin(RIt* it, RVec* v) { RIt t; t.p = func_001E9280(v); func_001E9270(it, v, &t); }
static inline void End(RIt* it, RVec* v) { RIt t; t.p = func_001E9250(v); func_001E9270(it, v, &t); }
static inline bool NeP(RNode** a, RNode** b) { return !(a == b); }
static inline bool Ne(RIt* a, RIt* b) { return !(a->p == b->p); }

#pragma push
#pragma opt_common_subs off
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (HasKids(&n->children)) {
        bool found = 0;
        RIt it, end;
        RIt q, e;
        Begin(&it, &n->children);
        q = it;
        End(&end, &n->children);
        e = end;
        while (Ne(&q, &e)) {
            if (Check(*q.p, t)) { found = 1; break; }
            q.p++;
        }
        return found;
    }
    return 0;
}


#pragma pop
#undef cTreeNode_cSkaSystemPtr_HasChildren /* merge_units */
#undef cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe /* merge_units */
#undef func_001E9010 /* merge_units */
#undef func_001E9030 /* merge_units */
#undef cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2 /* merge_units */
#undef func_001E9060 /* merge_units */
static inline void merge_flush_func_001E9090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9090 */
