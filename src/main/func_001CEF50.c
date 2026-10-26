#include "types.h"
typedef struct { void** p; } It_EF50;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x53]; int lA4[3]; } S_EF50;
extern void** std_vector_imp_cXformNodePtr_1_begin(void* v);
extern void** std_vector_imp_cXformNodePtr_1_end(void* v);
extern void std_vector_cXformNodePtr_pointer2iterator(It_EF50* out, void* v, void*** p);
extern void cArray_cXformNodePtr_Begin(It_EF50* it, void* c);
extern void cArray_cXformNodePtr_End(It_EF50* it, void* c);
extern int cArray_cXformNodePtr_ConstIterator_opNe(It_EF50* a, It_EF50* b);
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_EF50* it);
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_EF50* it);
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



