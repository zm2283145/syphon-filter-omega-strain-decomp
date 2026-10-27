/*
 * SFOGame/Source/humanIk: 2 files, 001CEF10-001CEF50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CEF10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

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
extern void cArray_cXformNodePtr_Begin(It_EF50* it, void* c);
extern void cArray_cXformNodePtr_End(It_EF50* it, void* c);
#if 0 /* merge_units */
extern int cArray_cXformNodePtr_ConstIterator_opNe(It_EF50* a, It_EF50* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */

extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_EF50* it);
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
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
static inline void merge_flush_func_001CEF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEF50 */
