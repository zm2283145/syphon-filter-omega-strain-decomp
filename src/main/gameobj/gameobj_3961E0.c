/*
 * main/gameobj: range (4 files, 003961E0-003963B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_release_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003961E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector through its allocator, optionally delete. */
extern "C" {
char D_004BC4E0[] = "allocator.hh";
}
DEFINE_VECTOR_RELEASE_DTOR(std_vector_deleter_cSkaAnimAnchorListEntry_dtor, std_vector_deleter_cSkaAnimAnchorListEntry_clear, opDelete_cSkaAnimAnchorListEntryP_int_bool_charP_etc, D_004BC4E0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003961E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003961E0 */

/* merge_units: begin func_00396260 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" void* cSkaAnimAnchor_dtor(void* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
#if 0 /* merge_units */
void* cSkaAnimAnchor_dtor(void* self, short flags);
#endif /* merge_units */
#define cSkaAnimAnchor_dtor(a0, a1) (cSkaAnimAnchor_dtor((a0), (a1))) /* merge_units */

void opDelete_cSkaAnimAnchorListEntryP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_cSkaAnimAnchorListEntryP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            cSkaAnimAnchor_dtor((char*)allocation + 16, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#undef cSkaAnimAnchor_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396260 */

/* merge_units: begin func_00396340 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct Node_3963B0 { unsigned char pad[0xB0]; struct Node_3963B0* owner; int children; } Node_3963B0;
extern "C" Node_3963B0* cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor(Node_3963B0* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

/* Deleting destructor: member cleanup, then base destructor. */
#if 0 /* merge_units */
extern "C" void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

extern "C" void cSkaAnimAnchor_TreeNode_DetachParent(void* self);
extern "C" void cSkaAnimAnchor_TreeNode_DetachChildren(void* self);
#if 0 /* merge_units */
extern "C" void* cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor(void* self, short deleteFlag);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor(a0, a1) ((void *)cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor((Node_3963B0 *)(a0), (a1))) /* merge_units */


extern "C" void* cSkaAnimAnchor_dtor(void* self, short deleteFlag)
{
    if (self) {
        if (self) {
            cSkaAnimAnchor_TreeNode_DetachParent(self);
            cSkaAnimAnchor_TreeNode_DetachChildren(self);
            cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396340 */

/* merge_units: begin func_003963B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: unlink from the owner, orphan all children, free the list. */
typedef struct { int w[1]; } It_3963B0;


extern "C" {
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Remove_OrderNotPreserved(void* vec, Node_3963B0** value);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(It_3963B0* out, void* vec);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(It_3963B0* out, void* vec);
bool cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(It_3963B0* a, It_3963B0* b);
Node_3963B0** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(It_3963B0* it);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(It_3963B0* it);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Clear(void* vec);
void* std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_dtor(void* vec, short deleteFlag);
#if 0 /* merge_units */
void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}

extern "C" Node_3963B0* cTreeNode_cSkaAnimAnchor_TreeNodeData_dtor(Node_3963B0* self, short deleteFlag)
{
    if (self) {
        Node_3963B0* me = self;
        It_3963B0 it;
        It_3963B0 end;
        if (self->owner) {
            cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Remove_OrderNotPreserved(&self->owner->children, &me);
            me->owner = 0;
        }
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&it, &self->children);
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&end, &self->children);
        for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&it))
            (*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&it))->owner = 0;
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Clear(&self->children);
        {
            void* v = &self->children;
            if (v)
                std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_dtor(v, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003963B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003963B0 */
