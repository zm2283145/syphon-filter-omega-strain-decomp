/*
 * SFOGame/Source/human: 3 files, 0019D4E0-0019D560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019D4E0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cQuaternion_InvertUnitQuat(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D4E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D4E0 */

/* merge_units: begin func_0019D500 */
#pragma push /* merge_units */
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* self);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(void* self);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
void* cSkaAnimAnchor_GetRotation(void* self) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(self);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self);
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self) + 0x50;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D500 */

/* merge_units: begin func_0019D560 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float value; } AnimTarget;
extern AnimTarget* std_vector_cSkaSliderValue_opIndex(void* curve);

/* Returns the target value (+0x10) of the channel's curve at +0x88. */
float cSkaSystem_GetSliderValue(char* self)
{
    return std_vector_cSkaSliderValue_opIndex(self + 0x88)->value;
}
static inline void merge_flush_func_0019D560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D560 */
