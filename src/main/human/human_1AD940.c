/*
 * main/human: range (2 files, 001AD940-001AD9C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001AD940 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct { int pad0; int count; int* data; } PtrVec_1AD940;
extern void std_vector_pod_int_resize(PtrVec_1AD940* v, int n, int* fill);

void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(PtrVec_1AD940* v, int* value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == *value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    std_vector_pod_int_resize(v, last + 1, &fill);
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AD940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AD940 */

/* merge_units: begin func_001AD9C0 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } VP_1AD9C0;
typedef struct { char pad[0x50]; VP_1AD9C0 orient; char pad70[0x30]; unsigned char dirty; } Id_1AD9C0;
typedef struct { char pad[0x160]; int x160; } R_1AD9C0;
extern Id_1AD9C0* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(R_1AD9C0* self);
extern void cQuatVec_opAssign(VP_1AD9C0* d, VP_1AD9C0* s);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(R_1AD9C0* self);
extern void cQuatVec_ctor_void(VP_1AD9C0* p);
extern VP_1AD9C0* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(R_1AD9C0* self, VP_1AD9C0* tmp);
extern void cQuatVec_Transform(VP_1AD9C0* d, VP_1AD9C0* s);
extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(R_1AD9C0* self);
void cSkaAnimAnchor_SetTransform(R_1AD9C0* self, VP_1AD9C0* o)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, o);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        VP_1AD9C0 tmp;
        cQuatVec_ctor_void(&tmp);
        cQuatVec_Transform(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(self, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->dirty = 1;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(self);
    self->x160 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AD9C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AD9C0 */
