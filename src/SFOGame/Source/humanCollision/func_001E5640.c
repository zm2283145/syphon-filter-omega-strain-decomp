#include "types.h"
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
char* cSkaAnimAnchor_GetDeltaPos(void* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x20;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x70;
}