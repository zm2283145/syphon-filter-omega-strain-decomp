/*
 * SFOGame/Source/human: 1 file, 001A0280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A0280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void* RootCollection_FindByKey(void*, int);

int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(char* self) {
    return *(int*)(self + 176);
}

/* back(): address of the last element. */
int* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Back(PtrVec* v) {
    return v->data + v->count - 1;
}

/* Find in the root collection at +0xB0. */
void* cSkaSystem_GetAnchor(char* self, int key) {
    return RootCollection_FindByKey(self + 176, key);
}
static inline void merge_flush_func_001A0280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0280 */
