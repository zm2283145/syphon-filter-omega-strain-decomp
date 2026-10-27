/*
 * SFOGame/Source/humanIk: 4 files, 001CEE00-001CEF10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CEE00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_001CEE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE00 */

/* merge_units: begin func_001CEE20 */
#pragma push /* merge_units */
typedef struct { int* p; } F8It_1CE;
typedef struct { float m[4][4]; } F8Mtx_1CE;
typedef struct { char pad0[0x50]; unsigned char dirty; char pad51[0xF]; F8Mtx_1CE basis; char padA0[0x4]; char kids[4]; } F8Bone_1CE;
extern void cArray_cXformNodePtr_Begin(F8It_1CE* out, void* v);
extern void cArray_cXformNodePtr_End(F8It_1CE* out, void* v);
#if 0 /* merge_units */
extern int cArray_cXformNodePtr_ConstIterator_opNe(F8It_1CE* a, F8It_1CE* b);
#endif /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(); /* merge_units */

extern int* cArray_cXformNodePtr_ConstIterator_opMul(F8It_1CE* it);
#if 0 /* merge_units */
extern void cXformNode_SetNeedsUpdate(int child);
#endif /* merge_units */
void cXformNode_SetNeedsUpdate(); /* merge_units */

#if 0 /* merge_units */
extern F8It_1CE* cArray_cXformNodePtr_ConstIterator_opInc(F8It_1CE* it);
#endif /* merge_units */
Iter * cArray_cXformNodePtr_ConstIterator_opInc(); /* merge_units */

void cXformNode_SetRotationMatrix_ParentRelative(F8Bone_1CE* b, F8Mtx_1CE* m)
{
    b->basis.m[0][0] = m->m[0][0];
    b->basis.m[0][1] = m->m[0][1];
    b->basis.m[0][2] = m->m[0][2];
    b->basis.m[1][0] = m->m[1][0];
    b->basis.m[1][1] = m->m[1][1];
    b->basis.m[1][2] = m->m[1][2];
    b->basis.m[2][0] = m->m[2][0];
    b->basis.m[2][1] = m->m[2][1];
    b->basis.m[2][2] = m->m[2][2];
    b->basis.m[0][3] = m->m[0][3];
    b->basis.m[1][3] = m->m[1][3];
    b->basis.m[2][3] = m->m[2][3];
    if (!b->dirty) {
        F8It_1CE it;
        F8It_1CE end;
        F8It_1CE* pe;
        b->dirty = 1;
        cArray_cXformNodePtr_Begin(&it, b->kids);
        cArray_cXformNodePtr_End(&end, b->kids);
        pe = &end;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&it, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&it));
            cArray_cXformNodePtr_ConstIterator_opInc(&it);
        }
    }
}
static inline void merge_flush_func_001CEE20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE20 */

/* merge_units: begin func_001CEF10 */
#pragma push /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cXformNodePtr_ConstIterator_opInc(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_001CEF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEF10 */

/* merge_units: begin func_001CEF50 */
#pragma push /* merge_units */
typedef struct { void** p; } It_EF50;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x53]; int lA4[3]; } S_EF50;
extern void** std_vector_imp_cXformNodePtr_1_begin(void* v);
extern void** std_vector_imp_cXformNodePtr_1_end(void* v);
extern void std_vector_cXformNodePtr_pointer2iterator(It_EF50* out, void* v, void*** p);
#if 0 /* merge_units */
extern void cArray_cXformNodePtr_Begin(It_EF50* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((F8It_1CE *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_cXformNodePtr_End(It_EF50* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((F8It_1CE *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int cArray_cXformNodePtr_ConstIterator_opNe(It_EF50* a, It_EF50* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_EF50* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) ((void * *)cArray_cXformNodePtr_ConstIterator_opMul((F8It_1CE *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_EF50* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) ((void)cArray_cXformNodePtr_ConstIterator_opInc((Iter *)(a0))) /* merge_units */


void cXformNode_SetNeedsUpdate(S_EF50* o);
static inline int NotEq_EF50(void** a, It_EF50* b) { return !(a == b->p); }
static inline void Mark_EF50(S_EF50* o)
{
    It_EF50 b;
    It_EF50 e;
    if (!o->a50) {
        It_EF50* pe;
        o->a50 = 1;
        cArray_cXformNodePtr_Begin(&b, o->lA4);
        cArray_cXformNodePtr_End(&e, o->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
void cXformNode_SetNeedsUpdate(S_EF50* o)
{
    It_EF50 e;
    It_EF50 tb;
    It_EF50 te;
    void** pb;
    void** pe;
    It_EF50* ep;
    void** it;
    if (!o->a50) {
        o->a50 = 1;
        pb = std_vector_imp_cXformNodePtr_1_begin(o->lA4);
        std_vector_cXformNodePtr_pointer2iterator(&tb, o->lA4, &pb);
        it = tb.p;
        pe = std_vector_imp_cXformNodePtr_1_end(o->lA4);
        std_vector_cXformNodePtr_pointer2iterator(&te, o->lA4, &pe);
        e.p = te.p;
        ep = &e;
        for (; NotEq_EF50(it, ep); it++) {
            Mark_EF50((S_EF50*)*it);
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
static inline void merge_flush_func_001CEF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEF50 */
