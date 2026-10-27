/*
 * main/human: range (2 files, 001A7CD0-001A7D80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001A7CD0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7D80;
V4_7D80* cQuaternion_Rotate(V4_7D80* self, V4_7D80* o); /* gsynth: defined below */typedef struct { float m[4]; } E2Quat;
typedef struct { char pad[0xA0]; unsigned char dirty; } E2Ident;
typedef struct { char pad[0x160]; int f160; } E2Root;
extern E2Ident* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(E2Root*);
extern void* cJointInfo_Limits_InJointSpace(void*);
extern void cQuaternion_opAssign(void*, void*);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(E2Root*);
extern void cQuaternion_ctor_void(E2Quat*);
extern void* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(E2Root*, E2Quat*);
#if 0 /* merge_units */
extern void cQuaternion_Rotate(void*, void*);
#endif /* merge_units */
#define cQuaternion_Rotate(a0, a1) ((void)cQuaternion_Rotate((void *)(a0), (void *)(a1))) /* merge_units */

extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(E2Root*);
void cSkaAnimAnchor_SetRotation(E2Root* r, void* q) {
    E2Quat tmp;
    cQuaternion_opAssign(cJointInfo_Limits_InJointSpace((char*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r) + 0x50), q);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        cQuaternion_ctor_void(&tmp);
        cQuaternion_Rotate(cJointInfo_Limits_InJointSpace((char*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r) + 0x50), cSkaAnimAnchor_TreeNode_GetParentInverseRotation(r, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->dirty = 1;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(r);
    r->f160 = 0;
}
#undef cQuaternion_Rotate /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7CD0 */

/* merge_units: begin func_001A7D80 */
#pragma push /* merge_units */
static inline V4_7D80 QMul_(V4_7D80* a, V4_7D80* b) {
    V4_7D80 r; V4_7D80* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4_7D80* cQuaternion_Rotate(V4_7D80* self, V4_7D80* o) {
    V4_7D80 t; V4_7D80* tp; t = QMul_(self, o); tp = &t; *self = *tp;
    return self;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7D80 */
