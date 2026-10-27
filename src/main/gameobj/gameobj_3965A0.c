/*
 * main/gameobj: range (2 files, 003965A0-00396620)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003965A0 */
#pragma push /* merge_units */
typedef struct { void** data; int count; } G1Vec;
extern void* std_vector_pod_int_data(G1Vec* v);
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* p);
extern void cSkaAnimAnchor_TreeNode_DetachParent(void* p);
typedef struct { char pad[0xB4]; G1Vec v; } G1Obj;
#pragma opt_loop_invariants off
void cSkaAnimAnchor_TreeNode_DetachChildren(G1Obj* o)
{
    while (o->v.count != 0) {
        G1Vec* v = &o->v;
        void* e = ((void**)*(void**)std_vector_pod_int_data(v))[v->count - 1];
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(e) == o)
            cSkaAnimAnchor_TreeNode_DetachParent(e);
    }
}
#pragma opt_loop_invariants reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003965A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003965A0 */

/* merge_units: begin func_00396620 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: destroy all elements, then the base. */
typedef struct { int w[8]; } Iter_396620;
typedef struct { unsigned char pad[0x14]; int count; } Arr_396620;

extern "C" {
void std_deque_deleter_common_cSkaSystem_Request_make_iterator(Iter_396620* out, Arr_396620* a, int index);
void std_deque_deleter_cSkaSystem_Request_destroy(Arr_396620* a, Iter_396620* first, Iter_396620* last);
void* std_deque_deleter_common_cSkaSystem_Request_dtor(Arr_396620* a, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Arr_396620* std_deque_deleter_cSkaSystem_Request_dtor(Arr_396620* self, short deleteFlag)
{
    if (self) {
        Iter_396620 first;
        Iter_396620 last;
        std_deque_deleter_common_cSkaSystem_Request_make_iterator(&last, self, self->count);
        std_deque_deleter_common_cSkaSystem_Request_make_iterator(&first, self, 0);
        std_deque_deleter_cSkaSystem_Request_destroy(self, &first, &last);
        std_deque_deleter_common_cSkaSystem_Request_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396620 */
