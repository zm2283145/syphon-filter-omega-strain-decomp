/*
 * SFOGame/Source/GuiAgentInfo: 25 files, 00362890-00363810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00362890 */
#pragma push /* merge_units */
#include "types.h"
#include "root_mark_dirty_tree.h"

/* Mark a node and its children dirty. */
DEFINE_ROOT_MARK_DIRTY_TREE(func_00362890)
static inline void merge_flush_func_00362890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362890 */

/* merge_units: begin func_00362940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_00362940(char* self) {
    return *(int*)(self + 0);
}

void func_00362950(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00362970(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00362980(char* self) {
    return self + 180;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362940 */

/* merge_units: begin func_00362990 */
#pragma push /* merge_units */
typedef struct { char pad[0xB8]; int v; } ObjB8;
/* Returns whether the field at +0xB8 is set. */
int func_00362990(ObjB8* o) { return !(o->v == 0); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362990 */

/* merge_units: begin func_003629B0 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } QPair;

#pragma peephole off
/* Copies a pair of quadwords and returns the destination (unit built with the peephole pass off). */
QPair* func_003629B0(QPair* dst, QPair* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003629B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003629B0 */

/* merge_units: begin func_003629D0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003629D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003629D0 */

/* merge_units: begin func_00362AE0 */
#pragma push /* merge_units */
void* func_00362AE0(void* self) {
    return self;
}
static inline void merge_flush_func_00362AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362AE0 */

/* merge_units: begin func_00362AF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
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
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct Nd { Plc world; char pad20[0x30]; Plc local; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; Nd* parent; };
extern "C" {
#if 0 /* merge_units */
Nd* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Nd* n);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) ((Nd *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((F8Root *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cSkaAnimAnchor_TreeNode_UpdateTransform(Nd* n);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_UpdateTransform(a0) (cSkaAnimAnchor_TreeNode_UpdateTransform((F8Root *)(a0))) /* merge_units */

#if 0 /* merge_units */
Nd* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(Nd* n);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) ((Nd *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cQuaternion_opAssign(V4* d, V4* s);
#endif /* merge_units */
#define cQuaternion_opAssign(a0, a1) ((void)cQuaternion_opAssign((Vec4 *)(a0), (Vec4 *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cVector_opAssign(V4* d, V4* s);
#endif /* merge_units */
#define cVector_opAssign(a0, a1) ((void)cVector_opAssign((Vec4 *)(a0), (Vec4 *)(a1))) /* merge_units */

#if 0 /* merge_units */
V4* cQuatVec_Rotation(Plc* p);
#endif /* merge_units */
#define cQuatVec_Rotation(a0) ((V4 *)cQuatVec_Rotation((F8Plc *)(a0))) /* merge_units */

#if 0 /* merge_units */
V4* cQuatVec_Translation(Plc* p);
#endif /* merge_units */
#define cQuatVec_Translation(a0) ((V4 *)cQuatVec_Translation((F8Plc *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cQuatVec_Rotate(Plc* p, V4* q);
#endif /* merge_units */
#define cQuatVec_Rotate(a0, a1) (cQuatVec_Rotate((F8RootW *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cQuatVec_Translate(Plc* p, V4* v);
#endif /* merge_units */
#define cQuatVec_Translate(a0, a1) (cQuatVec_Translate((F8RootW *)(a0), (void *)(a1))) /* merge_units */

void cQuaternion_ctor_void(V4* q);
void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c);
void cQuaternion_ctor_cQuaternionR(V4* d, V4* s);
}
static inline Plc* WorldX(Nd* n)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(n)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(n);
        return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->world;
    }
    return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->local;
}
static inline void Refresh(Nd* n)
{
    Nd* gp = n->parent;
    if (gp && n->dirty) {
        Plc* gw = WorldX(gp);
        Plc* w;
        Plc* l = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->local;
        w = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->world;
        cQuaternion_opAssign(&w->rot, &l->rot);
        cVector_opAssign(&w->pos, &l->pos);
        Plc* w2 = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->world;
        cQuatVec_Rotate(w2, cQuatVec_Rotation(gw));
        cQuatVec_Translate(w2, cQuatVec_Translation(gw));
        n->dirty = 0;
    }
}
static inline Plc* World(Nd* n)
{
    if (n->parent) {
        Refresh(n);
        return &n->world;
    }
    return &n->local;
}
extern "C" void Root_RefreshWorldCache_362AF0(Nd* self)
{
    Nd* par = self->parent;
    if (par && self->dirty) {
        Plc* pw = World(par);
        { Plc* s = &self->local; QC(&self->world.rot, &s->rot); QC(&self->world.pos, &s->pos); }
        V4 r;
        V4 m;
        cQuaternion_ctor_void(&m);
        cQuaternion_VU0Multiply(&m, &pw->rot, &self->world.rot);
        cQuaternion_ctor_cQuaternionR(&r, &m);
        { void* xx = &r; /* dead on purpose: retail keeps this addiu */ }
        V4* v = &self->world.pos;
        QC(&self->world.rot, &r);
        QRot(v, &pw->rot);
        VAdd3(&pw->pos, &self->world.pos);
        self->dirty = 0;
    }
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
#undef cSkaAnimAnchor_TreeNode_UpdateTransform /* merge_units */
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#undef cQuaternion_opAssign /* merge_units */
#undef cVector_opAssign /* merge_units */
#undef cQuatVec_Rotation /* merge_units */
#undef cQuatVec_Translation /* merge_units */
#undef cQuatVec_Rotate /* merge_units */
#undef cQuatVec_Translate /* merge_units */
static inline void merge_flush_func_00362AF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362AF0 */

/* merge_units: begin func_00362CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_00362CE0(char* self) {
    return *(int*)(self + 176);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362CE0 */

/* merge_units: begin func_00362CF0 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x40]; Q v; } Obj40;

/* Copies a quadword into the object's field at +0x40. */
void func_00362CF0(Obj40* obj, Q* v)
{
    obj->v = *v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362CF0 */

/* merge_units: begin func_00362D00 */
#pragma push /* merge_units */
typedef struct { char pad[0x7C]; float angle; char pad80[0x4E0 - 0x80]; float speed; } S362D00;
extern void GuiWidget_onAdvanceTime(S362D00* self, float dt);
#pragma opt_propagation off
void GuiAgentDisplay_onAdvanceTime(S362D00* self, float dt) {
    GuiWidget_onAdvanceTime(self, dt);
    self->angle += 3.1415927f * (dt / 30.0f) * self->speed;
    if (self->angle > 3.1415927f) self->angle -= 6.2831855f;
    else if (self->angle < -3.1415927f) self->angle += 6.2831855f;
}
static inline void merge_flush_func_00362D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362D00 */

/* merge_units: begin func_00362DC0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on

/* GuiAgentDisplay_onWake: (re)builds the front-end agent model of the agent display widget:
 * camera and turntable matrices, appearance copied from the widget's block, body model,
 * collision spheres, idle animation, and the default display parameters.
 * Same model set-up as GuiAgentModify_ctor (GuiAgentModify/GuiAgentModify_ctor.c). */

struct V4_A1 { float x, y, z, w; };
struct M4_A1 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_A1 { __int128 r[4]; };
static inline void M4Cp_A1(M4Q_A1* d0, const M4Q_A1* s0) { M4Q_A1* d = d0; __int128 qa, qb; const M4Q_A1* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Ent_A1 { __int128 a; __int128 b; };
struct Name_A1 { char s[16]; };
struct Sph_A1 { char pad[0x20]; };
struct SVec_A1 { char pad[0x10]; };
struct Word_A1 { int w; };
struct H_A1 { char pad[0xC]; int serial; };

class Xf_A1 {
public:
    VPAD2(a) virtual void SetMtx(M4_A1* m);
};

struct Man_A1 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    Ent_A1 e[(0x23C0 - 0x80) / 0x20];
    unsigned short cnt;
    char pad23C2[0x23F0 - 0x23C2];
    float f23F0;
    float f23F4;
    char pad23F8[0x2BD0 - 0x23F8];
    int f2BD0;
    char pad2BD4[0x2C04 - 0x2BD4];
    void* f2C04;
    char pad2C08[0x2C0D - 0x2C08];
    signed char b2C0D;
    char pad2C0E[0x2C11 - 0x2C0E];
    unsigned char b2C11;
    char pad2C12[0x2D70 - 0x2C12];
    H_A1* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_A1 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_A1 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_A1* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_A1* xf;
    char pad54[0xC];
    Man_A1 man;
};

struct Blk_A1 { char d[0x440]; };
struct GDef_A1 { Name_A1 name; int i; float f[7]; };

struct Self_A1 {
    void* vt;
    char pad4[0x48 - 0x4];
    Model_A1* model;
    char pad4C[0x50 - 0x4C];
    Name_A1 name;
    int i60;
    float f64[7];
    char pad80[0xA0 - 0x80];
    Blk_A1 app;
    float speed;
};

extern "C" {
extern char D_004BBA00[];
extern char D_004BBA10[];
extern void* D_004F77A0;
extern GDef_A1 D_0056F9B0;
void GuiWidget_onAdd(Self_A1* self);
float SIN(float a);
float COS(float a);
void cMatrix_Set_ColumnMajorForm(M4_A1* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
unsigned short SKL_CountAttribs(void* app);
unsigned short SKL_AddBlankParts(void* app, unsigned short n);
void cMan_SortParts(Man_A1* m);
int SKL_FindSex(void* app);
void cSKM_GOBJ_ResetSkeleton(Model_A1* m, char* name);
void Libc_Strcpy(char* d, const char* s);
void cArrayCapacity_ctor(Word_A1* w, int n);
void cArray_cSkeletonBBoxContributionPtr_ctor(SVec_A1* v, Word_A1* w, unsigned char f);
V4_A1* cVector_ctor_float_float_float_float(V4_A1* v, float x, float y, float z, float w);
void cSkeletonBBoxContribution_ctor(Sph_A1* s, int bone, float r, V4_A1* off);
void cArray_cSkeletonBBoxContributionPtr_PushBackActual(SVec_A1* v, Sph_A1** p);
void cSkeletonBBoxContribution_dtor(Sph_A1* s, int f);
void* cSKM_GOBJ_GetSkeleton_void_2(Model_A1* m);
void cSkeleton_ResetBBoxContributors(void* n, SVec_A1* v);
void cArray_cSkeletonBBoxContributionPtr_dtor(SVec_A1* v, int f);
void cSkaParams_HandleNewAnimationSet(void* a, void* b);
void cSkaSystem_SetInitialAnimation(void* a);
void cMan_SetGunOffsets(Man_A1* m);
void cMan_GetTextureIDs(Man_A1* m);
void cMan_BuildMan(Man_A1* m, int flag);
void cMan_SetBoneSet(Man_A1* m, int a);
void GuiAgentDisplay_onWake(Self_A1* self);
}

/* quadword block copy (addi loop counter, hand-scheduled delay slot): not expressible in C */
static inline void QCopy_A1(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v0, -0x10(d)
        .set reorder
    }
}

static inline Man_A1* MANP_A1(Model_A1* m) { return &m->man; }
static inline char* APP_A1(Man_A1* m) { return m->app; }
static inline char* NAME_A1(Man_A1* m) { return m->name; }
static inline V4_A1* Splat_A1(V4_A1* t, float) { float z = 0.0f; return cVector_ctor_float_float_float_float(t, z, z, z, z); }
static inline void Spheres_A1(Model_A1* md)
{
            Word_A1 w;
            {
                SVec_A1 vec;
                Sph_A1 arr[12];
                V4_A1 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
                int k;
                cArrayCapacity_ctor(&w, 0x15);
                cArray_cSkeletonBBoxContributionPtr_ctor(&vec, &w, 1);
                cSkeletonBBoxContribution_ctor(&arr[0], 0, 0.75f, Splat_A1(&t0, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[1], 4, 0.41666666f, Splat_A1(&t1, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[2], 6, 0.41666666f, Splat_A1(&t2, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[3], 0xC, 0.75f, Splat_A1(&t3, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[4], 0x10, 0.75f, Splat_A1(&t4, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[5], 0xE, 1.0f, Splat_A1(&t5, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[6], 0xD, 0.33333334f, Splat_A1(&t6, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[7], 0xF, 0.33333334f, Splat_A1(&t7, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[8], 0x11, 0.33333334f, Splat_A1(&t8, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[9], 0x12, 0.33333334f, Splat_A1(&t9, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[10], 0x13, 0.6666667f, Splat_A1(&t10, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[11], 0x14, 0.6666667f, Splat_A1(&t11, 0.0f));
                for (k = 0; k < 12; k++) {
                    Sph_A1* sp; Sph_A1** pp = &sp; sp = &arr[k]; cArray_cSkeletonBBoxContributionPtr_PushBackActual(&vec, pp);
                }
                cSkeletonBBoxContribution_dtor(&arr[11], -1);
                cSkeletonBBoxContribution_dtor(&arr[10], -1);
                cSkeletonBBoxContribution_dtor(&arr[9], -1);
                cSkeletonBBoxContribution_dtor(&arr[8], -1);
                cSkeletonBBoxContribution_dtor(&arr[7], -1);
                cSkeletonBBoxContribution_dtor(&arr[6], -1);
                cSkeletonBBoxContribution_dtor(&arr[5], -1);
                cSkeletonBBoxContribution_dtor(&arr[4], -1);
                cSkeletonBBoxContribution_dtor(&arr[3], -1);
                cSkeletonBBoxContribution_dtor(&arr[2], -1);
                cSkeletonBBoxContribution_dtor(&arr[1], -1);
                cSkeletonBBoxContribution_dtor(&arr[0], -1);
                cSkeleton_ResetBBoxContributors(cSKM_GOBJ_GetSkeleton_void_2(md), &vec);
                cArray_cSkeletonBBoxContributionPtr_dtor(&vec, -1);
            }
}
static inline void QAsgB_A1(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline char* Buf_A1(Model_A1* m) { return (char*)m + 0x2E50; }
static inline void SetF_A1(Model_A1* md, float v) { md->man.f23F0 = v; }
static inline int& Neg1_A1(int& d) { d = -1; return d; }
static inline int& Ser_A1(H_A1* o, int& d) { return *(o ? &o->serial : &Neg1_A1(d)); }
static inline void SetS_A1(Model_A1* md, short v) { md->man.s2D94 = v; }
static inline void SetB_A1(Model_A1* md, unsigned char v) { md->man.b2C11 = v; }
static inline void Tail_A1(Self_A1* self, V4_A1& v)
{
    int d;
            {
                Spheres_A1(self->model);
            }
            {
                void** an;
                void* a = D_004F77A0;
                an = (void**)((char*)self->model + 0x2EC0);
                cSkaParams_HandleNewAnimationSet(an + 4, a);
                *an = a;
                cSkaSystem_SetInitialAnimation(an);
            }
            {
                SetF_A1(self->model, 1.0f);
                self->model->man.f23F4 = 0.0f;
                cMan_SetGunOffsets(&self->model->man);
            }
            {
                Man_A1* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { Model_A1* md = self->model; md->man.f2D70 = 0; m = &md->man; }
                m->f2D74 = Ser_A1(0, d);
                { QAsgB_A1(&m->pos, &v); m->pos.w = 1.0f; }
            }
            { Man_A1* mm = &self->model->man; mm->b2DA0 = 1; }
            cMan_GetTextureIDs(&self->model->man);
            {
                int c;
                Model_A1* m;
                c = 1; m = self->model; m->man.f2BD0 = c;
                cMan_BuildMan(&self->model->man, 1);
            }
            cMan_SetBoneSet(&self->model->man, -1);
            {
                SetS_A1(self->model, 0);
                SetB_A1(self->model, 1);
            }
}
extern "C" void GuiAgentDisplay_onWake(Self_A1* self)
{
    M4_A1 mtx;
    GuiWidget_onAdd(self);
    self->speed = 0.0f;
    {
        MANP_A1(self->model)->f2C04 = Buf_A1(self->model);
        {
            M4_A1 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_A1((M4Q_A1*)&mtx, (M4Q_A1*)&t);
        }
        self->model->SetMtx(&mtx);
    }
    {
        Xf_A1* xf = self->model->xf;
        M4_A1 rot;
        float s = SIN(0.0f);
        float c = COS(0.0f);
        { M4_A1* pr = &rot; float z = 0.0f; cMatrix_Set_ColumnMajorForm(pr, c, -s, z, s, c, z, z, z, 1.0f); }
        { M4_A1* pr = &rot; xf->SetMtx(pr); }
    }
    QCopy_A1(APP_A1(MANP_A1(self->model)), &self->app, 0x44);
    {
        Man_A1* m = &self->model->man;
        m->cnt = SKL_CountAttribs(m->app);
    }
    {
        Man_A1* m = &self->model->man;
        m->cnt = SKL_AddBlankParts(m->app, m->cnt);
    }
    cMan_SortParts(&self->model->man);
    {
        char* nm; if (SKL_FindSex(APP_A1(&self->model->man)) == 0) nm = D_004BBA00; else { nm = D_004BBA10; asm { .set reorder } }
        cSKM_GOBJ_ResetSkeleton(self->model, nm);
        Libc_Strcpy(NAME_A1(&self->model->man), nm);
    }
    self->model->Init(1);
    { V4_A1 v; Tail_A1(self, v); }
    self->name = D_0056F9B0.name;
    self->i60 = D_0056F9B0.i;
    self->f64[0] = D_0056F9B0.f[0];
    self->f64[1] = D_0056F9B0.f[1];
    self->f64[2] = D_0056F9B0.f[2];
    self->f64[3] = D_0056F9B0.f[3];
    self->f64[4] = D_0056F9B0.f[4];
    self->f64[5] = D_0056F9B0.f[5];
    self->f64[6] = D_0056F9B0.f[6];
    self->f64[1] = 0.75f;
    self->f64[2] = 11.5f;
    self->f64[3] = 0.3f;
}
static inline void merge_flush_func_00362DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00362DC0 */

/* merge_units: begin func_003634D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; } Tmp;
typedef struct { char pad[4]; char name[0x50]; int count1; int count2; } Def;
typedef struct { char pad[0x24]; Def* def; char p2[0x50]; char list1[0x10]; char list2[0x18]; char sub[1]; } S;
typedef struct { int a, b; } Pair;
extern void cSkaAnimAnchorList_Reset(void*, void*);
extern void cSplinedMotion_Scalar0To1_ctor(Tmp*);
extern void cSkaSliderValue_opAssign(Tmp*, float);
extern void std_vector_imp_cSkaSliderValue_resize(void*, int, Tmp*);
extern void cSplinedMotion_Scalar0To1_dtor(Tmp*, int);
extern void std_vector_imp_cSkaSwitchValue_resize(void*, int, Pair*);
/* Binds a definition: copies its name and fills both lists with default entries. */
void Model_Attach_3634D0(S* s, Def* def)
{
    Tmp tmp;
    Pair p;
    s->def = def;
    cSkaAnimAnchorList_Reset(s->sub, def->name);
    cSplinedMotion_Scalar0To1_ctor(&tmp);
    cSkaSliderValue_opAssign(&tmp, 0.0f);
    std_vector_imp_cSkaSliderValue_resize(s->list1, def->count1, &tmp);
    cSplinedMotion_Scalar0To1_dtor(&tmp, -1);
    p.a = 0;
    p.b = 0;
    std_vector_imp_cSkaSwitchValue_resize(s->list2, def->count2, &p);
}
static inline void merge_flush_func_003634D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003634D0 */

/* merge_units: begin func_00363560 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "anim_channel_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00363560)
static inline void merge_flush_func_00363560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363560 */

/* merge_units: begin func_003635B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Anim channel destructor, optionally delete. */
DEFINE_ANIM_CHANNEL_DTOR_DEEP(func_003635B0)
static inline void merge_flush_func_003635B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003635B0 */

/* merge_units: begin func_00363620 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Anim channel destructor, optionally delete. */
DEFINE_ANIM_CHANNEL_DTOR(func_00363620)
static inline void merge_flush_func_00363620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363620 */

/* merge_units: begin func_00363680 */
#pragma push /* merge_units */
#include "GuiAgentInfo_types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Curve: only the slots used here are named (vtable offset in comments). */
struct Curve {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Sets start/current/target to v, re-evaluates the value (virtual +0x14) and returns self. */
extern "C" Curve* AnimChannels_ClearCount_363680(Curve* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00363680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00363680 */

/* merge_units: begin func_003636C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


extern int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(void* binding, CurveSegment* segment);
extern int cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(CurveSegment* segment, int from, int to, float t);
#pragma explicit_zero_data on
static float D_00492EE8 = 0.0f;
#pragma explicit_zero_data reset
static const float dat_00492EF0[24] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_Ctor(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = D_00492EE8;
    self->base.current = D_00492EE8;
    self->base.target = (*(float*)dat_00492EF0);
    self->base.rate = D_00492EE8;
    self->base.damping = 0.0f;
    cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(&self->base.segment, (int)&D_00492EE8, (int)&(*(float*)dat_00492EF0), 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003636C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003636C0 */

/* merge_units: begin func_00363760 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "anim_channel_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#pragma pop

#pragma cplusplus on

/* AnimChannelBase destructor, optionally delete. */
DEFINE_ANIM_CHANNEL_BASE_DTOR(func_00363760)
static inline void merge_flush_func_00363760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363760 */

/* merge_units: begin func_003637B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_003637B0)
static inline void merge_flush_func_003637B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003637B0 */

/* merge_units: begin func_00363800 */
#pragma push /* merge_units */
ValuePair* func_00363800(ValuePair* self, int value) {
    self->value = value;
    self->unk04 = 0;
    return self;
}
static inline void merge_flush_func_00363800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363800 */

/* merge_units: begin func_00363810 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_3810b { float v; float s; Key_3810b() {} };
struct Crv_3810b { Key_3810b k[2]; float dur; float inv; };
/* constant curve: both keys = (*a, *b * dur), store duration and its inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_3810b* Curve_InitConstant_363810(Crv_3810b* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_3810b* e = c->k; do { new (e) Key_3810b; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
static inline void merge_flush_func_00363810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363810 */

/* merge_units: begin func_00363890 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00363890)
static inline void merge_flush_func_00363890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363890 */

/* merge_units: begin func_003638E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_003638E0)
static inline void merge_flush_func_003638E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003638E0 */

/* merge_units: begin func_00363930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00363930, std_vector_imp_cSkeletonBBoxContributionPtr_1_dtor)
static inline void merge_flush_func_00363930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363930 */

/* merge_units: begin func_00363990 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00363990)
static inline void merge_flush_func_00363990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363990 */
