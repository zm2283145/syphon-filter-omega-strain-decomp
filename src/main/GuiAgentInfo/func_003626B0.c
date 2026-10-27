#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
typedef struct { int w[1]; } It;
static inline void QRot(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct Nd { char pad[0x50]; Plc p; char pad70[0x30]; unsigned char bA0; char padA1[0xF]; int bB0; };
extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Nd* n);
Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
void cQuatVec_opAssign(Plc* d, Plc* s);
void cQuatVec_InvertAssumingUnitQuat(Plc* p);
void cQuaternion_ctor_void(V4* q);
void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c);
void cQuaternion_ctor_cQuaternionR(V4* d, V4* s);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(Nd* n);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(It* out, void* vec);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(It* out, void* vec);
bool cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(It* a, It* b);
Nd** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(It* it);
void cSkaAnimAnchor_TreeNode_TellNeedToUpdate(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(It* it);
}
static inline void Cp(Plc* d, Plc* s) { QC(&d->rot, &s->rot); QC(&d->pos, &s->pos); }
extern "C" void Root_SetWorldPlacement_3626B0(Nd* self, Plc* src)
{
    { Plc* d = &self->p; QC(&d->rot, &src->rot); QC(&d->pos, &src->pos); }
    if (self->bB0) {
        Plc inv;
        V4 r;
        V4 m;
        Plc* p;
        Plc* ip;
        cQuatVec_opAssign(&inv, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self)));
        cQuatVec_InvertAssumingUnitQuat(&inv);
        ip = &inv;
        p = &self->p;
        cQuaternion_ctor_void(&m);
        cQuaternion_VU0Multiply(&m, &ip->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &m);
        { void* xx = &r; /* dead on purpose: retail keeps this addiu */ }
        QC(&p->rot, &r);
        V4* v = &p->pos;
        QRot(v, &ip->rot);
        VAdd3(&ip->pos, &p->pos);
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
