#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 q; V4 pos; } Plc;
typedef struct { int count; int* data; int cap; } PV;
typedef struct {
    Plc world;
    V4 x20;
    Plc x30;
    Plc local;
    V4 x70;
    Plc x80;
    unsigned char fA0;
    unsigned char fA1;
    unsigned char fA2;
} RId;
typedef struct Root {
    char pad[0xB0];
    struct Root* parent;
    PV children;
} Root;

extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(Root* r);
extern Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root* r);
extern void cQuatVec_ctor_cQuatVecR(Plc* d, Plc* s);
extern V4* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(Root* r);
extern void cVector_ctor_cVectorR(V4* d, V4* s);
extern Plc* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(Root* r);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(Root* r);
extern void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root* r, Plc* p);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(Root* r, V4* v);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(Root* r, Plc* p);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(Root* r);
extern RId* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(Root* r);
extern int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_PushBackActual(PV* v, Root* volatile* value);
extern RId* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(Root* r);
extern void cQuatVec_opAssign(Plc* d, Plc* s);
extern Plc* cQuatVec_ctor_void(Plc* p);
extern Plc* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(Root* r, Plc* out);
extern void cQuatVec_Transform(Plc* d, Plc* s);
extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(Root* r);
extern void cVector_opAssign(V4* d, V4* s);
extern V4* cQuaternion_ctor_void(V4* v);
extern V4* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(Root* r, V4* out);
extern void cVector_Rotate_cQuaternionR(V4* d, V4* s);

static inline Plc* RootPlc_(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->world;
    }
    return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->local;
}

static inline V4* RootMot_(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->x20;
    }
    return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->x70;
}

static inline Plc* RootPose_(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(r);
        return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->x30;
    }
    return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->x80;
}

static inline void Attach_(Root* parent, Root* volatile child)
{
    cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(child);
    child->parent = parent;
    cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_PushBackActual(&parent->children, &child);
}

static inline void SetA0_(Root* r, unsigned char v) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->fA0 = v; }
static inline void SetA1_(Root* r, unsigned char v) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->fA1 = v; }
static inline void SetA2_(Root* r, unsigned char v) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->fA2 = v; }

static inline void SetLocalPlc_(Root* r, Plc* p)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->local, p);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        Plc t;
        RId* id;
        cQuatVec_ctor_void(&t);
        id = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r);
        cQuatVec_Transform(&id->local, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(r, &t));
    }
    SetA0_(r, 1);
}

static inline void SetLocalMot_(Root* r, V4* m)
{
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(r);
    cVector_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->x70, m);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        V4 t;
        RId* id;
        cQuaternion_ctor_void(&t);
        id = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r);
        cVector_Rotate_cQuaternionR(&id->x70, cSkaAnimAnchor_TreeNode_GetParentInverseRotation(r, &t));
    }
    SetA1_(r, 1);
}

static inline void SetLocalPose_(Root* r, Plc* p)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->x80, p);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        Plc t;
        RId* id;
        cQuatVec_ctor_void(&t);
        id = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r);
        cQuatVec_Transform(&id->x80, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(r, &t));
    }
    SetA2_(r, 1);
}

/* gcc-style asm copy: MW asm{} or plain struct copy mis-orders the &p1 address vs the lq */
static inline void GCp(void* d, const void* s) { void* dd = d; const void* ss = s; __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=&r"(t) : "r"(ss), "r"(dd) : "memory"); }
void cSkaAnimAnchor_TreeNode_AttachParent(Root* r, Root* parent)
{
    Plc p1;
    V4 m;
    Plc p2;

    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        Plc a;
        V4 b;
        Plc c;
        cQuatVec_ctor_cQuatVecR(&a, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r));
        cVector_ctor_cVectorR(&b, cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(r));
        cQuatVec_ctor_cQuatVecR(&c, cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(r));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(r);
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, &a);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(r, &b);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(r, &c);
    }
    { Plc* s = RootPlc_(r); GCp(&p1.q, &s->q); GCp(&p1.pos, &s->pos); }
    m = *RootMot_(r);
    { Plc* s = RootPose_(r); GCp(&p2.q, &s->q); GCp(&p2.pos, &s->pos); }
    Attach_(parent, r);
    SetLocalPlc_(r, &p1);
    SetLocalMot_(r, &m);
    SetLocalPose_(r, &p2);
}








