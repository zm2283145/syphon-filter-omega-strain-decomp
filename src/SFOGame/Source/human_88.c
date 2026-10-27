/*
 * SFOGame/Source/human: 7 files, 001A7370-001A7780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A7370 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "vu0_quat_rot.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Rotate_cQuaternionR(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(b)
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
        sqc2 vf6, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7370 */

/* merge_units: begin func_001A73C0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_73C0;
typedef struct { char pad[0xB0]; void* root; } Obj_73C0;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
#pragma push
#pragma opt_propagation off
V4_73C0* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(Obj_73C0* o, V4_73C0* out)
{
    void* r = o->root;
    V4_73C0* v;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        v = (V4_73C0*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
        asm { .set reorder } /* empty barrier keeps the then-arm separate (known trick) */
    } else {
        v = (V4_73C0*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
    }
    VCopyFF(out, v);
    asm {
        lqc2 vf1, 0x0(out)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(out)
    }
    return out;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A73C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A73C0 */

/* merge_units: begin func_001A7440 */
#pragma push /* merge_units */
typedef struct { V4 rot; V4 pos; } P;
typedef struct { char pad[0xB0]; void* root; } Obj;
static inline V4* CopyVec(V4* d, V4* s) { *d = *s; return d; }
static inline P* PCopy(P* d, P* s) { CopyVec(&d->rot, &s->rot); CopyVec(&d->pos, &s->pos); return d; }
static inline P* PInvert(P* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    /* empty barrier: changes block scheduling so the then-arm's call arg lands in the jal delay slot */
    { V4* v; asm { .set reorder } v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* Copies the parent's world placement into out and inverts it in place. */
P* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(Obj* o, P* out)
{
    void* r = o->root;
    P* v;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        v = (P*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
        asm { .set reorder }
    } else {
        v = (P*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
    }
    PCopy(out, v);
    PInvert(out);
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7440 */

/* merge_units: begin func_001A7530 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int);

void* cQuatVec_ctor_void(void* self) {
    return self;
}

/* push_back: insert one value at end(). */
int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_PushBackActual(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001A7530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7530 */

/* merge_units: begin func_001A7560 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Recomputes a root's cached world pose (w at 0x30) from its local placement
 * (p at 0x80) and the parent's world placement when the dirty flag is set. */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    /* The unused xx keeps retail's dead source-address addiu. */
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };

extern "C" {
#if 0 /* merge_units */
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) ((void *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((a0))) /* merge_units */

void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
void cQuatVec_opAssign(Plc*, void*);
void cQuatVec_InvertAssumingUnitQuat(Plc*);
void cQuaternion_ctor_void(V*);
void cQuaternion_VU0Multiply(V*, V*, V*);
void cQuaternion_ctor_cQuaternionR(V*, V*);
void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(struct S* s);
#if 0 /* merge_units */
void cSkaAnimAnchor_TreeNode_UpdateTransform(void*);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_UpdateTransform(a0) (cSkaAnimAnchor_TreeNode_UpdateTransform((a0))) /* merge_units */

#if 0 /* merge_units */
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */

}

struct S {
    char pad00[0x30];
    Plc w;              /* 0x30 */
    char pad50[0x30];
    Plc p;              /* 0x80 */
    char padA0[2];
    unsigned char ba2;  /* 0xA2 */
    char padA3[0xD];
    void* ib0;          /* 0xB0 */
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

static inline Plc* WorldPlc(void* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return (Plc*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return (Plc*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
}

void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(S* s)
{
    if (s->ba2) {
        Plc* pi = WorldPlc(s->ib0);
        {
            Plc* o = &s->p;
            Plc* d = &s->w;
            Q16(&d->rot, &o->rot);
            Q16(&d->pos, &o->pos);
        }
        Plc* p = &s->w;
        V r;
        V q;
        cQuaternion_ctor_void(&q);
        cQuaternion_VU0Multiply(&q, &pi->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &q);
        p->rot = r;
        QRot(&p->pos, &pi->rot);
        VAdd3(&pi->pos, &p->pos);
        s->ba2 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7560(void) {}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
#undef cSkaAnimAnchor_TreeNode_UpdateTransform /* merge_units */
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7560 */

/* merge_units: begin func_001A76A0 */
#pragma push /* merge_units */
typedef struct { V4 r[4]; } M4;
typedef struct { char pad[0x20]; V4 v20; char pad30[0x40]; V4 v70; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* root; } Obj_001A76A0;

extern V4* cQuatVec_Rotation(void* p);
extern M4* cMatrix_ctor_cQuaternionR(M4* m, V4* q);
extern V4* cQuatVec_Translation(void* p);
extern M4* cMatrix_Set_cMatrixR_cVectorR(M4* m, M4* b, V4* p);
#pragma opt_common_subs off
static inline char* GetWorld(void* r) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50;
}
void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(Obj_001A76A0* o)
{
    if (o->dirty) {
        char* v = GetWorld(o->root);
        VCopyF(&o->v20, &o->v70);
        {
            M4 m; M4 rot; M4* b; V4* d;
            b = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(v));
            cMatrix_Set_cMatrixR_cVectorR(&m, b, cQuatVec_Translation(v));
            d = &o->v20;
            {
                M4* mp = &m;
                asm {
                    lqc2 vf8, 0x0(d)
                    lqc2 vf4, 0x0(mp)
                    lqc2 vf5, 0x10(mp)
                    lqc2 vf6, 0x20(mp)
                    vmulax.xyz ACC, vf4, vf8x
                    vmadday.xyz ACC, vf5, vf8y
                    vmaddz.xyz vf8, vf6, vf8z
                    sqc2 vf8, 0x0(d)
                }
            }
        }
        o->dirty = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A76A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A76A0 */

/* merge_units: begin func_001A7780 */
#pragma push /* merge_units */
void* cTreeNode_cSkaSystemPtr_Data(void* self) {
    return self;
}

int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cMatrix_GetYAxis(char* self) {
    return self + 8;
}
static inline void merge_flush_func_001A7780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7780 */
