/*
 * main/human: range (5 files, 0019FE90-001A01C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019FE90 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Sets a root's local placement; when it has a parent (ib0 set), the placement
 * is re-expressed relative to the inverse of the parent's world placement. */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    /* The unused xx keeps retail's dead source-address addiu. */
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };

extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
void cQuatVec_opAssign(Plc*, void*);
void cQuatVec_InvertAssumingUnitQuat(Plc*);
void cQuaternion_ctor_void(V*);
void cQuaternion_VU0Multiply(V*, V*, V*);
void cQuaternion_ctor_cQuaternionR(V*, V*);
void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(struct S* s, Plc* in);
}

struct S {
    char pad00[0x80];
    Plc p;              /* 0x80 */
    char padA0[2];
    unsigned char ba2;  /* 0xA2 */
    char padA3[0xD];
    int ib0;            /* 0xB0 */
};

static inline void QRot(V* v, V* q) {
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
static inline void VAdd3(V* s, V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(S* s, Plc* in)
{
    {
        Plc* d = &s->p;
        Q16(&d->rot, &in->rot);
        Q16(&d->pos, &in->pos);
    }
    if (s->ib0) {
        Plc inv;
        cQuatVec_opAssign(&inv, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(s)));
        cQuatVec_InvertAssumingUnitQuat(&inv);
        Plc* p;
        Plc* pi = &inv;
        p = &s->p;
        V r;
        V q;
        cQuaternion_ctor_void(&q);
        cQuaternion_VU0Multiply(&q, &pi->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &q);
        p->rot = r;
        QRot(&p->pos, &pi->rot);
        VAdd3(&pi->pos, &p->pos);
    }
    s->ba2 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FE90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019FE90 */

/* merge_units: begin func_0019FFC0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x70]; V4 q; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* parent; } R;
#if 0 /* merge_units */
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(R*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((void *)(a0))) /* merge_units */

extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern V4* cQuatVec_Rotation(void*);
extern V4* cQuaternion_opAssign(V4*, V4*);
extern V4* cQuaternion_InvertUnitQuat(V4*);
static inline void QRot_(V4* q, V4* v) {
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

#pragma peephole off
#pragma opt_propagation off
/* Sets the local orientation quat; when parented, rotates it into the parent's frame. */
void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(R* self, V4* q)
{
    V4 t;
    {V4* d = &self->q; asm { .set reorder } *d = *q;}
    if (self->parent) {
        cQuaternion_opAssign(&t, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self))));
        cQuaternion_InvertUnitQuat(&t);
        QRot_(&t, &self->q);
    }
    self->dirty = 1;
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FFC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019FFC0 */

/* merge_units: begin func_001A0080 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { int pad0; int count; int* data; } PtrVec_1A0080;
typedef struct { char pad[0xB4]; PtrVec_1A0080 list; } Owner_1A0080;
typedef struct { char pad[0xB0]; Owner_1A0080* owner; } O_1A0080;
extern void std_vector_pod_int_resize(PtrVec_1A0080* v, int n, int* fill);
static inline void Remove_1A0080(PtrVec_1A0080* v, int value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    std_vector_pod_int_resize(v, last + 1, &fill);
}
void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(O_1A0080* o)
{
    if (o->owner) {
        Remove_1A0080(&o->owner->list, (int)o);
        o->owner = 0;
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A0080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A0080 */

/* merge_units: begin func_001A0110 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; float rot[0x14]; float wrot[8]; char pad80[0x2]; unsigned char dirty; char padA3[0xD]; void* xform; } RootIdn_f4;
extern RootIdn_f4* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
#if 0 /* merge_units */
extern void cQuatVec_opAssign(void*, void*);
#endif /* merge_units */
#define cQuatVec_opAssign(a0, a1) (cQuatVec_opAssign((void *)(a0), (a1))) /* merge_units */

extern void cQuatVec_Transform(void*, void*);
void* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(RootIdn_f4* self)
{
    void* pl;
    if (self->xform != 0) {
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty) {
            pl = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self));
            cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->rot, cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->wrot);
            cQuatVec_Transform(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->rot, pl);
            cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty = 0;
        }
        return self->rot;
    }
    return self->wrot;
}
#undef cQuatVec_opAssign /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A0110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A0110 */

/* merge_units: begin func_001A01C0 */
#pragma push /* merge_units */
typedef struct { float m[4][4]; } Mtx_e1;
typedef struct { char pad[0x20]; float pos[4]; char pad30[0x40]; float wpos[4]; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* motion; } RootIdn_e1;
#if 0 /* merge_units */
extern RootIdn_e1* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) ((RootIdn_e1 *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */

extern void cVector_opAssign(float*, float*);
extern Mtx_e1* cMatrix_ctor_cQuatVecR(Mtx_e1*, void*);
extern void cVector_Rotate_cMatrixR(float*, Mtx_e1*);
float* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(RootIdn_e1* self)
{
    Mtx_e1 m;
    void* pl;
    if (self->motion != 0) {
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty) {
            pl = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self));
            cVector_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->pos, cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->wpos);
            cVector_Rotate_cMatrixR(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->pos, cMatrix_ctor_cQuatVecR(&m, pl));
            cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty = 0;
        }
        return self->pos;
    }
    return self->wpos;
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A01C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A01C0 */
