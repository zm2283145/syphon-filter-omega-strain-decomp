#pragma opt_common_subs off
#include "types.h"
typedef struct { char pad[0x10]; int set; } E_1A08D0;
typedef struct { E_1A08D0*** p; } It_1A08D0;
typedef struct { int n; } SIt_1A08D0;
typedef struct { char pad[0x108]; int vec; } O_1A08D0;
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(int* v);
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(int* v);
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(It_1A08D0* out, int* v, E_1A08D0**** p);
extern void* cSkaParams_GetAnimAnchorList(int* s);
extern void cArray_cSkaAnimAnchorListEntry_Begin(SIt_1A08D0* out, void* s);
extern void cArray_cSkaAnimAnchorListEntry_End(SIt_1A08D0* out, void* s);
extern int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(SIt_1A08D0* a, SIt_1A08D0* b);
extern void* cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(SIt_1A08D0* a);
extern void* cSkaAnimAnchorListEntry_Anchor(void* p);
extern void cSkaAnimAnchor_DetachParent(void* p);
extern void cArray_cSkaAnimAnchorListEntry_Iterator_opInc(SIt_1A08D0* a);
static inline int Eq_1A08D0(E_1A08D0*** a, E_1A08D0*** b) { return a == b; }
void MotionCtrl_DetachRoots(O_1A08D0* self)
{
    It_1A08D0 b;
    It_1A08D0 e;
    E_1A08D0*** t0;
    E_1A08D0*** t1;
    SIt_1A08D0 i;
    SIt_1A08D0 ie;
    int* v = &self->vec;
    E_1A08D0*** it;
    E_1A08D0*** end;
    t0 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&b, v, &t0);
    it = b.p;
    t1 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&e, v, &t1);
    end = e.p;
    while (Eq_1A08D0(it, end) ^ 1) {
        void* s = cSkaParams_GetAnimAnchorList(&(**it)->set);
        cArray_cSkaAnimAnchorListEntry_Begin(&i, s);
        cArray_cSkaAnimAnchorListEntry_End(&ie, s);
        while (cArray_cSkaAnimAnchorListEntry_Iterator_opNe(&i, &ie)) {
            cSkaAnimAnchor_DetachParent(cSkaAnimAnchorListEntry_Anchor(cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(&i)));
            cArray_cSkaAnimAnchorListEntry_Iterator_opInc(&i);
        }
        it++;
    }
}
