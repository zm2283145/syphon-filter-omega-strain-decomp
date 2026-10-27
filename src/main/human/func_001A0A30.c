#include "types.h"
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