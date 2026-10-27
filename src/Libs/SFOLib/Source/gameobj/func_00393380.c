#pragma cplusplus on
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    /* xx: dead on purpose, retail keeps the duplicate address addiu of the copy target */
    V(const V& o) { void* xx = this; __int128 q; V* pd = this; const V* ps = &o; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
} __attribute__((aligned(16)));
struct Plc { V rot; V pos; };
struct Ident { char pad[0x50]; Plc orient; V pos; Plc pose; unsigned char d160; unsigned char d161; unsigned char d162; };
struct Root { char pad[0xB0]; Root* owner; char children[4]; };

extern "C" {
int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Root* r);
void cSkaAnimAnchor_TreeNode_UpdateTransform(Root* r);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(Root* r);
void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(Root* r);
void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(Root* r);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Remove_OrderNotPreserved(void* vec, Root** value);
Ident* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(Root* r);
void cQuatVec_opAssign(Plc* d, Plc* s);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(Root* r);
void cQuatVec_ctor_void(Plc* p);
Plc* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(Root* r, Plc* tmp);
void cQuatVec_Transform(Plc* d, Plc* s);
void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(Root* r);
void cVector_opAssign(V* d, V* s);
void cQuaternion_ctor_void(V* q);
V* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(Root* r, V* out);
void cVector_Rotate_cQuaternionR(V* a, V* b);
}

static inline Plc* WorldOrient(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return (Plc*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return (Plc*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
}
static inline V* WorldPos(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return (V*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x20);
    }
    return (V*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x70);
}
static inline Plc* WorldPose(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(r);
        return (Plc*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x30);
    }
    return (Plc*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x80);
}
static inline void Detach(Root* self)
{
    Root* me = self;
    if (me->owner) {
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Remove_OrderNotPreserved(me->owner->children, &me);
        me->owner = 0;
    }
}
static inline void SetOrient(Root* self, Plc* o)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, o);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        Plc tmp;
        cQuatVec_ctor_void(&tmp);
        cQuatVec_Transform(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(self, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->d160 = 1;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(self);
}
static inline void SetPos(Root* self, V* p)
{
    cVector_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->pos, p);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        V q;
        cQuaternion_ctor_void(&q);
        cVector_Rotate_cQuaternionR(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->pos, cSkaAnimAnchor_TreeNode_GetParentInverseRotation(self, &q));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->d161 = 1;
}
static inline void SetPose(Root* self, Plc* o)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->pose, o);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        Plc tmp;
        cQuatVec_ctor_void(&tmp);
        cQuatVec_Transform(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->pose, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(self, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->d162 = 1;
}

extern "C" void cSkaAnimAnchor_TreeNode_DetachParent(Root* self)
{
    if (self->owner) {
        Plc o = *WorldOrient(self);
        V p = *WorldPos(self);
        Plc q = *WorldPose(self);
        Detach(self);
        SetOrient(self, &o);
        SetPos(self, &p);
        SetPose(self, &q);
    }
}
