#include "types.h"

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
