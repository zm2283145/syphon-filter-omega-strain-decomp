/*
 * main/human: range (2 files, 00191390-001913E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00191390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(char* self) {
    return self + 180;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191390 */

/* merge_units: begin func_001913E0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB8]; void* unkB8; } ObjB8;

/* Returns whether the pointer field at +0xB8 is set. */
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(ObjB8* o)
{
    return (o->unkB8 == 0) ^ 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001913E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001913E0 */
