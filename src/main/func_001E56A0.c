#include "types.h"
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void* cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(void* r) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r) != 0) {
        cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x30;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x80;
}