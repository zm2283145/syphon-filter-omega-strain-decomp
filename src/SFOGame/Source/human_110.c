/*
 * SFOGame/Source/human: 2 files, 001B2670-001B26A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B2670 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cStatesWithHistory_1_ClearAllStates(char* self) {
    *(int*)(self + 8) = 0;
}

/* Shift the three-entry history down by one. */
void cStatesWithHistory_1_NextFrame(int* history) {
    history[0] = history[1];
    history[1] = history[2];
}
static inline void merge_flush_func_001B2670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2670 */

/* merge_units: begin func_001B26A0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_001B26A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B26A0 */
