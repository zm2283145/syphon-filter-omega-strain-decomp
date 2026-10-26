/*
 * main/human: range (3 files, 001A0720-001A07F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_001A0720 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(func_001A0720, D_004DA890, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001A0720 */

/* merge_units: begin func_001A0780 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIBodyMovedMsg_dtor, D_004DCC70, D_004DCD70, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001A0780 */

/* merge_units: begin func_001A07F0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma bool off
typedef struct { int pad0; int x4; } E_1A07F0;
typedef struct { E_1A07F0** p; } It_1A07F0;
typedef struct { char pad[8]; int vec; int xC; } O_1A07F0;
extern E_1A07F0** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(int* v);
extern E_1A07F0** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(int* v);
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(It_1A07F0* out, int* v, E_1A07F0*** p);
static inline int Eq_1A07F0(E_1A07F0** a, E_1A07F0** b) { return a == b; }
void ActorRelation_Clear(O_1A07F0* self)
{
    It_1A07F0 b;
    It_1A07F0 e;
    E_1A07F0** t0;
    E_1A07F0** t1;
    E_1A07F0** it;
    E_1A07F0** end;
    t0 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(&self->vec);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&b, &self->vec, &t0);
    it = b.p;
    t1 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(&self->vec);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&e, &self->vec, &t1);
    end = e.p;
    while (Eq_1A07F0(it, end) ^ 1) {
        (*it)->x4 = 0;
        it++;
    }
    self->xC = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A07F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A07F0 */
