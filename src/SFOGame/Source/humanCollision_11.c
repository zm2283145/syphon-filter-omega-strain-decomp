/*
 * SFOGame/Source/humanCollision: 3 files, 001E1F10-001E2100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1F10 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma cplusplus on

typedef struct { V4 rot; V4 pos; } Plc;
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
static inline V4 MulS(V4* a, float k) {
    V4 r;
    V4* d = &r;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    }
    return r;
}
static inline void MulS2(V4* d, V4* a, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    }
}
static inline V4 MulS3(V4* a, float k) { V4 r; MulS2(&r, a, k); return r; }
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct VC { float x, y, z, w; VC() {} VC(const VC& o) { VC* dd = this; QC(dd, &o); } } __attribute__((aligned(16)));
static inline VC MulV(V4* a, float k) { VC r; int t; VC* d = &r; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } return r; }
static inline VC MulV2(V4* a, float k) { VC r; VC* d = &r; MulS2((V4*)d, a, k); return *d; }
static inline V4 MulW(V4* a, float k) { V4 r; V4* d = &r; MulS2(d, a, k); return *d; }
static inline void SetPos(Plc* p, V4* v) { V4* dd = &p->pos; QC(dd, v); }
static inline void SetPos2(V4* d, V4* v) { V4* dd = d; QC(dd, v); }
struct Nd { char pad[0x50]; Plc p; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; int bB0; };
typedef struct { int w[1]; } It;
extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Nd* n);
Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
void cQuatVec_opAssign(Plc* d, Plc* s);
void cQuatVec_InvertAssumingUnitQuat(Plc* p);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(Nd* n);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(It* out, void* vec);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(It* out, void* vec);
bool cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(It* a, It* b);
Nd** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(It* it);
void cSkaAnimAnchor_TreeNode_TellNeedToUpdate(Nd* n);
void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(It* it);
}
#pragma opt_propagation off
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(Nd* self, V4* pos)
{
    { Plc* d = &self->p; V4* dd = &d->pos; QC(dd, pos); }
    if (self->bB0) {
        Plc inv; Plc* ip; Plc* p; V4* ipos; V4* v;
        cQuatVec_opAssign(&inv, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self)));
        cQuatVec_InvertAssumingUnitQuat(&inv);
        p = &self->p;
        ip = &inv;
        v = &p->pos;
        ipos = &ip->pos;
        QRot(v, &ip->rot);
        float* pw = &v->w;
        float w = *pw;
        if (1.0f == w) {
            VAdd3(ipos, v);
        } else {
            VC t = MulV(ipos, w); V4* tq = (V4*)&t;
            VAdd3(tq, v);
            float* pw2 = &v->w; *pw2 = t.w;
        }
    }
    self->dirty = 1;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(self)) {
        It it, end;
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&it, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&end, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));
        for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&it))
            cSkaAnimAnchor_TreeNode_TellNeedToUpdate(*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&it));
    }
}
static inline void merge_flush_func_001E1F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1F10 */

/* merge_units: begin func_001E20C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of FxNode: only the slots used here are named (vtable offset in comments). */
struct FxNode {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Method58(); /* +0x58 */
    char pad04[0x40 - 4];
    char sub40[0x10];     /* +0x40 */
    unsigned char flag50; /* +0x50 */
};

/* Calls the virtual at vtable+0x58 when the flag at +0x50 is set; returns the sub-object at +0x40. */
extern "C" void* cXform_GetTranslation(FxNode* self)
{
    if (self->flag50)
        self->Method58();
    return self->sub40;
}
static inline void merge_flush_func_001E20C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E20C0 */

/* merge_units: begin func_001E2100 */
#pragma push /* merge_units */
void cXform_Transform(V4* a, V4* b) {
    char* pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        lqc2 vf8, 0x0(pv1)
        lqc2 vf9, 0x10(pv1)
        lqc2 vf10, 0x20(pv1)
        lqc2 vf11, 0x30(pv1)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(pv1)
        sqc2 vf13, 0x10(pv1)
        sqc2 vf14, 0x20(pv1)
        sqc2 vf15, 0x30(pv1)
    }
}
static inline void merge_flush_func_001E2100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E2100 */
