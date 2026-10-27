/*
 * main/ska: range (2 files, 003AF0C0-003AF130)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003AF0C0 */
#pragma push /* merge_units */
SkaDirtyFlags* cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor(SkaDirtyFlags* dst, SkaDirtyFlags* src); /* gsynth: defined below */Rel* std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor(Rel* r); /* gsynth: defined below */
typedef struct { char b[0x50]; } AnimRegion;
typedef struct { char b[0x10]; } AnimDirty;
typedef struct { char b[0xC]; unsigned char valid; } AnimRelations;
typedef struct {
    AnimRegion a;
    AnimRegion b;
    AnimDirty dirty;
    int unkB0;
    AnimRelations rel;
} AnimRoot;
extern void cSkaAnimAnchor_TreeNodeData_tData_ctor(AnimRegion* dst, AnimRegion* src);
#if 0 /* merge_units */
extern void cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor(AnimDirty* dst, AnimDirty* src);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor(a0, a1) ((void)cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor(AnimRelations* rel);
#endif /* merge_units */
#define std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor(a0) ((void)std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor((void *)(a0))) /* merge_units */


/* Copies an animation root: both regions and the dirty flags; resets the relations. */
AnimRoot* cTreeNode_cSkaAnimAnchor_TreeNodeData_ctor(AnimRoot* dst, AnimRoot* src)
{
    AnimRelations* rel;
    cSkaAnimAnchor_TreeNodeData_tData_ctor(&dst->a, &src->a);
    cSkaAnimAnchor_TreeNodeData_tData_ctor(&dst->b, &src->b);
    cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor(&dst->dirty, &src->dirty);
    rel = &dst->rel;
    dst->unkB0 = 0;
    std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor(rel);
    rel->valid = 1;
    return dst;
}
#undef cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor /* merge_units */
#undef std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF0C0 */

/* merge_units: begin func_003AF130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


Rel* std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

SkaDirtyFlags* cSkaAnimAnchor_TreeNodeData_tNeedsUpdate_ctor(SkaDirtyFlags* dst, SkaDirtyFlags* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF130 */
