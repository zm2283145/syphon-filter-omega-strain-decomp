/*
 * main/ska: range (3 files, 003BA210-003BA290)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003BA210 */
#pragma push /* merge_units */
SkaRelFlag* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(SkaRelFlag* self); /* gsynth: defined below */
typedef struct TmpB0 {
    char b[0xB0];
} TmpB0;

typedef struct ObjB0 {
    char pad[0xB0];
    int unkB0;
    char sub[4];
} ObjB0;

extern void cSkaAnimAnchor_TreeNodeData_ctor_void(TmpB0*);
extern void cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(ObjB0*, TmpB0*);
#if 0 /* merge_units */
extern void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(void*);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(a0) ((void)cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void((void *)(a0))) /* merge_units */


/* Constructor: initializes from a default temporary and sets up the sub-object at +0xB4. */
ObjB0* cSkaAnimAnchor_TreeNode_ctor_void(ObjB0* o) {
    TmpB0 tmp;
    cSkaAnimAnchor_TreeNodeData_ctor_void(&tmp);
    cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(o, &tmp);
    o->unkB0 = 0;
    cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(o->sub);
    return o;
}
#undef cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA210 */

/* merge_units: begin func_003BA260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern Rel* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(Rel* r);

/* Construct: zero the three words and set the flag byte. */
SkaRelFlag* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(SkaRelFlag* self) {
    std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA260 */

/* merge_units: begin func_003BA290 */
#pragma push /* merge_units */
Rel* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA290(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA290 */
