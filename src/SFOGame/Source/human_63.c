/*
 * SFOGame/Source/human: 6 files, 0019D170-0019D3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019D170 */
#pragma push /* merge_units */
#include "types.h"

extern float Libc_Atan2f(float y, float x);

/* Heading angle of a 2D vector: atan2(-v[0], v[1]). */
float nSFOMath_GetZRotationFromYAxis(float* v)
{
    return Libc_Atan2f(-v[0], v[1]);
}
static inline void merge_flush_func_0019D170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D170 */

/* merge_units: begin func_0019D180 */
#pragma push /* merge_units */
float nSFOMath_GetZRotationFromXAxis(float* v) {
    return Libc_Atan2f(v[1], v[0]);
}
static inline void merge_flush_func_0019D180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D180 */

/* merge_units: begin func_0019D190 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

void* func_0019D190(char* self) {
    return self + 16;
}

void* cMatrix_GetXAxis(void* self) {
    return self;
}

/* Copy a 3x4 block: xyz of each row first, then the w column. */
Mtx34* Mtx34_Copy(Mtx34* dst, Mtx34* src) {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[0][1];
    dst->m[0][2] = src->m[0][2];
    dst->m[1][0] = src->m[1][0];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[1][2];
    dst->m[2][0] = src->m[2][0];
    dst->m[2][1] = src->m[2][1];
    dst->m[2][2] = src->m[2][2];
    dst->m[0][3] = src->m[0][3];
    dst->m[1][3] = src->m[1][3];
    dst->m[2][3] = src->m[2][3];
    return dst;
}

void* std_vector_deleter_cTargetZRotationStackSlot_data(char* self) {
    return self + 8;
}

int std_vector_imp_cTargetZRotationStackSlot_size(char* self) {
    return *(int*)(self + 4);
}

void* cHuman_GetLedgeAnchor_void(Actor* actor) {
    return actor->edgeRoot;
}
static inline void merge_flush_func_0019D190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D190 */

/* merge_units: begin func_0019D250 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D250;
typedef struct { V4_D250 r[4]; } M4_D250;
static inline float GetX_D250(V4_D250* v) { return v->x; }
static inline float GetY_D250(V4_D250* v) { return v->y; }
static inline float GetZ_D250(V4_D250* v) { return v->z; }
static inline float H180_D250(V4_D250* v) { return Libc_Atan2f(GetY_D250(v), GetX_D250(v)); }
static inline float H170_D250(float* v) { return Libc_Atan2f(-v[0], v[1]); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
float Mtx_GetHeading(M4_D250* m)
{
    V4_D250 r0;
    V4_D250 r1;
    V4_D250* d0 = &r0;
    asm { .set reorder } /* empty barrier keeps the &r0 addiu ahead of the row loads (known trick) */
    *d0 = m->r[0];
    r1 = m->r[1];
    return GetZ_D250(&r0) < GetZ_D250(&r1) ? H180_D250(&r0) : H170_D250(&r1.x);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D250 */

/* merge_units: begin func_0019D2C0 */
#pragma push /* merge_units */
typedef struct { float v[4]; } __attribute__((aligned(16))) V4D4;
typedef struct { float m[3][4]; V4D4 pos; } MtxD4;
typedef struct { V4D4 quat; V4D4 pos; } Placement;
static inline MtxD4* QuatToMtx_19D2C0(MtxD4* a, V4D4* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}static inline MtxD4* FromBasis_19D2C0(MtxD4* d, MtxD4* b, V4D4* p)
{
    d->m[0][0] = b->m[0][0];
    d->m[0][1] = b->m[0][1];
    d->m[0][2] = b->m[0][2];
    d->m[1][0] = b->m[1][0];
    d->m[1][1] = b->m[1][1];
    d->m[1][2] = b->m[1][2];
    d->m[2][0] = b->m[2][0];
    d->m[2][1] = b->m[2][1];
    d->m[2][2] = b->m[2][2];
    d->m[0][3] = b->m[0][3];
    d->m[1][3] = b->m[1][3];
    d->m[2][3] = b->m[2][3];
    d->pos = *p;
    return d;
}
#pragma inline_depth(10)
#pragma peephole off
#pragma opt_propagation off
static inline V4D4* PlGetQuat_19D2C0(Placement* p) { return &p->quat; }
static inline V4D4* PlGetPos_19D2C0(Placement* p) { return &p->pos; }
MtxD4* cMatrix_ctor_cQuatVecR(MtxD4* out, Placement* pl)
{
    MtxD4 rot;
    V4D4* pos = PlGetPos_19D2C0(pl);
    QuatToMtx_19D2C0(&rot, PlGetQuat_19D2C0(pl));
    return FromBasis_19D2C0(out, &rot, pos);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D2C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D2C0 */

/* merge_units: begin func_0019D3B0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_0019D3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D3B0 */
