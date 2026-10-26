/*
 * main/human: range (2 files, 0019FDE0-0019FDF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019FDE0 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; } Obj4;
/* Returns whether the field at +4 is zero. */
int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Empty(Obj4* o) { return o->unk4 == 0; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FDE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019FDE0 */

/* merge_units: begin func_0019FDF0 */
#pragma push /* merge_units */
typedef struct VecPair {
    Q a;
    Q b;
} VecPair;

typedef struct RootB0 {
    char pad00[0xB0];
    void* owner; /* 0xB0 */
} RootB0;

extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(RootB0* root);
extern void* Root_GetWorldPlacement(RootB0* root);
extern void VecPair_Copy(VecPair* dst, void* src);
extern void* Root_GetWorldMotion(RootB0* root);
extern void Vec4_Assign(Q* dst, void* src);
extern void* SceneRoot_GetPoseCache(RootB0* root);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(RootB0* root);
extern void Root_SetWorldPlacement(RootB0* root, VecPair* placement);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(RootB0* root, Q* motion);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(RootB0* root, VecPair* pair);

/* When owned by owner and dirty, snapshots placement/motion, resets the root and restores them. */
void cSkaAnimAnchor_TreeNode_DetachChild(void* owner, RootB0* root) {
    VecPair saved;
    Q motion;
    VecPair placement;
    if (root->owner == owner && cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(root)) {
        VecPair_Copy(&placement, Root_GetWorldPlacement(root));
        Vec4_Assign(&motion, Root_GetWorldMotion(root));
        VecPair_Copy(&saved, SceneRoot_GetPoseCache(root));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(root);
        Root_SetWorldPlacement(root, &placement);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(root, &motion);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(root, &saved);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FDF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019FDF0 */
