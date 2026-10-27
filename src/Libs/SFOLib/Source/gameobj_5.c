/*
 * Libs/SFOLib/Source/gameobj: 3 files, 00392F50-00393000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00392F50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cSkaTransPlaybackPtr_dtor)
static inline void merge_flush_func_00392F50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392F50 */

/* merge_units: begin func_00392FD0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Word* cLListIterator_cSkaTransPlaybackPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkaTransPlaybackPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00392FD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392FD0 */

/* merge_units: begin func_00393000 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: unlink from the owner, orphan all children, free the list. */
typedef struct { int w[1]; } It_3963B0;
typedef struct Node_3963B0 { unsigned char pad[4]; struct Node_3963B0* owner; int children; } Node_3963B0;

extern "C" {
void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(void* vec, Node_3963B0** value);
void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(It_3963B0* out, void* vec);
void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(It_3963B0* out, void* vec);
bool cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(It_3963B0* a, It_3963B0* b);
Node_3963B0** cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(It_3963B0* it);
void cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(It_3963B0* it);
void cArray_cTreeNode_cSkaSystemPtrPtr_Clear(void* vec);
void* std_vector_cTreeNode_cSkaSystemPtrPtr_dtor(void* vec, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Node_3963B0* cTreeNode_cSkaSystemPtr_dtor(Node_3963B0* self, short deleteFlag)
{
    if (self) {
        Node_3963B0* me = self;
        It_3963B0 it;
        It_3963B0 end;
        if (self->owner) {
            cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(&self->owner->children, &me);
            me->owner = 0;
        }
        cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(&it, &self->children);
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void(&end, &self->children);
        for (; cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(&it))
            (*cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(&it))->owner = 0;
        cArray_cTreeNode_cSkaSystemPtrPtr_Clear(&self->children);
        {
            void* v = &self->children;
            if (v)
                std_vector_cTreeNode_cSkaSystemPtrPtr_dtor(v, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00393000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393000 */
