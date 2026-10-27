#pragma cplusplus on
#include "types.h"
#pragma always_inline on
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* pd = this; const V4* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V4& operator=(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
typedef struct { int w[1]; } It;
struct R { char pad[0x50]; V4 q; char pad60[0x40]; unsigned char bA0; char padA1[0xF]; void* parent; };
extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(R*);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
V4* cQuatVec_Rotation(void*);
V4* cQuaternion_opAssign(V4*, V4*);
V4* cQuaternion_InvertUnitQuat(V4*);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(R* n);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(R* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(It* out, void* vec);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(It* out, void* vec);
bool cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(It* a, It* b);
R** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(It* it);
void cSkaAnimAnchor_TreeNode_TellNeedToUpdate(R* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(It* it);
}
static inline V4 QMul(const V4& a, const V4& b)
{
    V4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%1)" : : "r"(&a), "r"(&r), "r"(&b) : "memory");
    return r;
}
#pragma peephole off
#pragma opt_propagation off
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(R* self, V4* q)
{
    V4 t;
    self->q = *q;
    if (self->parent) {
        cQuaternion_opAssign(&t, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self))));
        cQuaternion_InvertUnitQuat(&t);
        { V4* pt = &t; V4* pq = &self->q; *pq = QMul(*pt, *pq); }
    }
    self->bA0 = 1;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(self)) {
        It it, end;
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&it, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&end, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&it))
            cSkaAnimAnchor_TreeNode_TellNeedToUpdate(*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&it));
    }
}
