/*
 * SFOGame/Source/human: 3 files, 001A6D00-001A6D90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A6D00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_001A6D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A6D00 */

/* merge_units: begin func_001A6D40 */
#pragma push /* merge_units */
extern void cSkaAnimAnchor_TreeNode_AttachParent(void* child, void* parent);
extern void cSkaAnimAnchor_ClearLocalTransform(void* child);
void cSkaAnimAnchor_AttachChild(void* parent, void* child, int reset) {
    cSkaAnimAnchor_TreeNode_AttachParent(child, parent);
    if (reset) {
        cSkaAnimAnchor_ClearLocalTransform(child);
    }
}
static inline void merge_flush_func_001A6D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A6D40 */

/* merge_units: begin func_001A6D90 */
#pragma push /* merge_units */
typedef struct VecPair {
    Q a;
    Q b;
} VecPair;

typedef struct RootIdentity {
    char pad00[0x50];
    char orientation[0x50]; /* 0x50 */
    unsigned char dirty;    /* 0xA0 */
} RootIdentity;

extern void cQuatVec_GetUnit(VecPair* base);
extern RootIdentity* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(void* root);
extern void cQuatVec_opAssign(void* xform, VecPair* base);
extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(void* root);

/* Resets the root's local base to identity and propagates it to the children. */
void cSkaAnimAnchor_ClearLocalTransform(void* root) {
    VecPair base;
    int one;
    cQuatVec_GetUnit(&base);
    cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(root)->orientation, &base);
    one = 1;
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(root)->dirty = one;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(root);
}
static inline void merge_flush_func_001A6D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A6D90 */
