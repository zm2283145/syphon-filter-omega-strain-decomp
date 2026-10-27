#include "types.h"
typedef struct { Vec4 q; Vec4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { char pad0[0xA0]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(F8Root* r);
extern Vec4* cQuaternion_opAssign(Vec4* d, Vec4* s);
extern Vec4* cVector_opAssign(Vec4* d, Vec4* s);
extern void* cQuatVec_Rotation(F8Plc* p);
extern void* cQuatVec_Translation(F8Plc* p);
extern void cQuatVec_Rotate(F8RootW* w, void* q);
extern void cQuatVec_Translate(F8RootW* w, void* pos);
static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    cQuaternion_opAssign(&d->q, &s->q);
    cVector_opAssign(&d->pos, &s->pos);
}
F8RootW* Root_GetWorldPlacement_3629D0(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp;
            F8Plc* local;
            F8RootW* world;
            F8RootW* w;
            if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(p)) {
                cSkaAnimAnchor_TreeNode_UpdateTransform(p);
                pp = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->world;
            } else {
                pp = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->local;
            }
            F8PlcCopy(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->world, &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->local);
            w = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
            cQuatVec_Rotate(w, cQuatVec_Rotation(pp));
            cQuatVec_Translate(w, cQuatVec_Translation(pp));
            r->dirty = 0;
        }
        return (F8RootW*)r;
    }
    return (F8RootW*)&((F8RootW*)r)->local;
}
