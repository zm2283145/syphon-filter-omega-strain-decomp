#include "types.h"
typedef struct { Q a; Q b; } VP_1A0A30;
typedef struct { Q a; } V4_1A0A30;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* self);
extern VP_1A0A30* Root_GetWorldPlacement(void* self);
extern V4_1A0A30* Root_GetWorldMotion(void* self);
extern VP_1A0A30* SceneRoot_GetPoseCache(void* self);
extern void VecPair_Copy(VP_1A0A30* d, VP_1A0A30* s);
extern void Vec4_Assign(V4_1A0A30* d, V4_1A0A30* s);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(void* self);
extern void Root_SetWorldPlacement(void* self, VP_1A0A30* p);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(void* self, V4_1A0A30* m);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(void* self, VP_1A0A30* p);
void cSkaAnimAnchor_DetachParent(void* self)
{
    VP_1A0A30 place;
    V4_1A0A30 motion;
    VP_1A0A30 other;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        VecPair_Copy(&place, Root_GetWorldPlacement(self));
        Vec4_Assign(&motion, Root_GetWorldMotion(self));
        VecPair_Copy(&other, SceneRoot_GetPoseCache(self));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
        Root_SetWorldPlacement(self, &place);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(self, &motion);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(self, &other);
    }
}