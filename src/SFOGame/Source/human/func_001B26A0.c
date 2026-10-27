#include "types.h"
typedef struct E4Rid {
    char pad00[0x50];
    char orientation[0x50];
    unsigned char dirty;
} E4Rid;
typedef struct { Q a; Q b; } E4Pair;
extern E4Rid* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(void* root);
extern void* VecCurve_GetPrevious(void* o);
extern void cVector_opAssign(void* dst, void* src);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* root);
extern void cQuatVec_ctor_void(E4Pair* m);
extern void* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(void* root, E4Pair* m);
extern void cVector_Transform_cQuatVecR(void* p, void* m);
extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(void* root);
void cSkaAnimAnchor_SetPosition(void* root, void* pos)
{
    int one;
    cVector_opAssign(VecCurve_GetPrevious(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(root)->orientation), pos);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(root)) {
        E4Pair m;
        void* p;
        cQuatVec_ctor_void(&m);
        p = VecCurve_GetPrevious(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(root)->orientation);
        cVector_Transform_cQuatVecR(p, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(root, &m));
    }
    one = 1;
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(root)->dirty = one;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(root);
}