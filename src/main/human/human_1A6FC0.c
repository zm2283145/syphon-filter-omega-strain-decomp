/*
 * main/human: range (3 files, 001A6FC0-001A7040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001A6FC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int std_opEq_wrapiteratorR_wrapiteratorR(Iter* a, Iter* b) {
    return a->p == b->p;
}

int std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_opMul(char* self) {
    return *(int*)(self + 0);
}

void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A6FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A6FC0 */

/* merge_units: begin func_001A7030 */
#pragma push /* merge_units */
typedef struct { int unk0; void* p; } S;
/* Returns whether the second field is null. */
int std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_empty(S* s) { return s->p == 0; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7030 */

/* merge_units: begin func_001A7040 */
#pragma push /* merge_units */
int* std_vector_pod_int_end(PtrVec* v) {
    return v->data + v->count;
}

int std_vector_pod_int_begin(char* self) {
    return *(int*)(self + 8);
}

void* Root_IdentityAccessor(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7040 */
