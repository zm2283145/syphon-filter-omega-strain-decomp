/*
 * SFOGame/Source/human: 3 files, 001A09F0-001A0AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A09F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 384-byte elements. */
Iter16* cArray_cSkaAnimAnchorListEntry_Iterator_opInc(Iter16* it) {
    it->p = it->p + 384;
    return it;
}
static inline void merge_flush_func_001A09F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A09F0 */

/* merge_units: begin func_001A0A30 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } VP_1A0A30;
typedef struct { Q a; } V4_1A0A30;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* self);
extern V4_1A0A30* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(void* self);
extern void cQuatVec_ctor_cQuatVecR(VP_1A0A30* d, VP_1A0A30* s);
extern void cVector_ctor_cVectorR(V4_1A0A30* d, V4_1A0A30* s);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(void* self);
extern void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(void* self, VP_1A0A30* p);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(void* self, V4_1A0A30* m);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(void* self, VP_1A0A30* p);
void cSkaAnimAnchor_DetachParent(void* self)
{
    VP_1A0A30 place;
    V4_1A0A30 motion;
    VP_1A0A30 other;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        cQuatVec_ctor_cQuatVecR(&place, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self));
        cVector_ctor_cVectorR(&motion, cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(self));
        cQuatVec_ctor_cQuatVecR(&other, cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(self));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(self, &place);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(self, &motion);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(self, &other);
    }
}
static inline void merge_flush_func_001A0A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0A30 */

/* merge_units: begin func_001A0AD0 */
#pragma push /* merge_units */
void* cSkaAnimAnchorListEntry_Anchor(char* self) {
    return self + 16;
}

int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 384-byte elements. */
void cArray_cSkaAnimAnchorListEntry_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 384;
}

void cArray_cSkaAnimAnchorListEntry_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cSkaParams_GetAnimAnchorList(char* self) {
    return self + 160;
}
static inline void merge_flush_func_001A0AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0AD0 */
