/*
 * SFOGame/Source/game: 11 files, 00132530-00132800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00132530 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_2530;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
P_2530* cQuatVec_Rotate(P_2530* p, V4* q) {
    V4 u; V4 t;
    V4* vp;
    V4* s2;
    V4* rq;
    V4* s1x;
    V4* d1;
    rq = &t;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(rq)
    }
    d1 = &u;
    vp = &p->pos;
    s2 = &u;
    s1x = &t;
    *d1 = *s1x;
    p->rot = *s2;
    VU0_QROT(vp, q, vp)
    return p;
}
#pragma pop
static inline void merge_flush_func_00132530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132530 */

/* merge_units: begin func_001325E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Vec4* cVector_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

Vec4* cQuaternion_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self) {
    return self;
}
static inline void merge_flush_func_001325E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001325E0 */

/* merge_units: begin func_00132610 */
#pragma push /* merge_units */
typedef struct { V4 q; V4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { F8Plc world; char pad20[0x30]; F8Plc local; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
#if 0 /* merge_units */
extern F8RootW* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) ((F8RootW *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */


#if 0 /* merge_units */
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
#endif /* merge_units */
int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(); /* merge_units */

#if 0 /* merge_units */
extern V4* cQuaternion_opAssign(V4* d, V4* s);
#endif /* merge_units */
#define cQuaternion_opAssign(a0, a1) ((V4 *)cQuaternion_opAssign((Vec4 *)(a0), (Vec4 *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern V4* cVector_opAssign(V4* d, V4* s);
#endif /* merge_units */
#define cVector_opAssign(a0, a1) ((V4 *)cVector_opAssign((Vec4 *)(a0), (Vec4 *)(a1))) /* merge_units */


extern void* cQuatVec_Rotation(F8Plc* p);
extern void* cQuatVec_Translation(F8Plc* p);
#if 0 /* merge_units */
extern void cQuatVec_Rotate(F8RootW* w, void* q);
#endif /* merge_units */
#define cQuatVec_Rotate(a0, a1) ((void)cQuatVec_Rotate((P_2530 *)(a0), (V4 *)(a1))) /* merge_units */


extern void cQuatVec_Translate(F8RootW* w, void* pos);
#if 0 /* merge_units */
extern V4* cQuaternion_ctor_void(V4* self);
#endif /* merge_units */
void * cQuaternion_ctor_void(); /* merge_units */

extern void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c);
#if 0 /* merge_units */
extern V4* cQuaternion_ctor_cQuaternionR(V4* d, V4* s);
#endif /* merge_units */
Vec4 * cQuaternion_ctor_cQuaternionR(); /* merge_units */

void cSkaAnimAnchor_TreeNode_UpdateTransform(F8Root* r);
static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    cQuaternion_opAssign(&d->q, &s->q);
    cVector_opAssign(&d->pos, &s->pos);
}
static inline F8Plc* ParentPlc_(F8Root* p)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(p)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(p);
        return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->world;
    }
    return &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->local;
}
static inline F8Plc* RootWorld_(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp = ParentPlc_(p);
            F8RootW* w;
            F8PlcCopy(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->world, &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->local);
            w = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
            cQuatVec_Rotate(w, cQuatVec_Rotation(pp));
            cQuatVec_Translate(w, cQuatVec_Translation(pp));
            r->dirty = 0;
        }
        return (F8Plc*)r;
    }
    return &r->local;
}
/* GCC-style lq/sq quad copy: acts as a CSE barrier so MW recomputes addresses,
   and keeps a following dead address local alive (retail's dead addiu). */
static inline void Q6(void* d,const void* s){ __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_TreeNode_UpdateTransform(F8Root* r)
{
    F8Root* p = r->parent;
    if (p && r->dirty) {
        F8Plc* pp = RootWorld_(p);
        V4 u;
        V4 t;
        V4* vp;
        V4* pq;
        V4* pv;
        { V4* s = &r->local.q; Q6(&r->world.q,s); Q6(&r->world.pos,s+1); }
        cQuaternion_ctor_void(&t);
        cQuaternion_VU0Multiply(&t, &pp->q, &r->world.q);
        cQuaternion_ctor_cQuaternionR(&u, &t);
        r->world.q = u;
        { void* xx = &u; } /* dead: retail's duplicate addiu v1,sp,0x70 */
        vp = &r->world.pos;
        pq = &pp->q;
        VU0_QROT(vp, pq, vp)
        pv = &r->world.pos;
        vp = &pp->pos;
        asm {
            lqc2 vf1, 0x0(pv)
            lqc2 vf2, 0x0(vp)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0x0(pv)
        }
        r->dirty = 0;
    }
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#undef cQuaternion_opAssign /* merge_units */
#undef cVector_opAssign /* merge_units */
#undef cQuatVec_Rotate /* merge_units */
static inline void merge_flush_func_00132610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132610 */

/* merge_units: begin func_00132800 */
#pragma push /* merge_units */
Vec4* cQuaternion_ctor_cQuaternionR(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
static inline void merge_flush_func_00132800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132800 */

/* merge_units: begin func_00132810 */
#pragma push /* merge_units */
void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(a)
    }
}
static inline void merge_flush_func_00132810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132810 */

/* merge_units: begin func_00132840 */
#pragma push /* merge_units */
void* cQuaternion_ctor_void(void* self) {
    return self;
}

int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(char* self) {
    return *(int*)(self + 176);
}
static inline void merge_flush_func_00132840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132840 */

/* merge_units: begin func_00132860 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_2860;
struct Mdl_2860 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; V_2860 m[4]; unsigned char dirty; };
struct Ctx_2860 { char pad[0x2E78]; Mdl_2860* model; char pad2e7c[0x24]; V_2860 pos; };
/* anchor point (sibling of cSkeleton_GetCenterOfMass): refresh the model if dirty, transform pos by its matrix (VU0) */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" V_2860 cSKM_GOBJ_GetCenterOfMass(Ctx_2860* self)
{
    Mdl_2860* m = self->model;
    if (m->dirty) m->Update();
    V_2860 p;
    V_2860* mm;
    V_2860* pp;
    VCopyF(&p, &self->pos);
    mm = m->m;
    pp = &p;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf7, 0x30(mm)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}
#pragma pop
static inline void merge_flush_func_00132860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132860 */

/* merge_units: begin func_00132900 */
#pragma push /* merge_units */
void cXform_UpdateTreeNode(char* self) {
    self[80] = 0;
}
static inline void merge_flush_func_00132900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132900 */

/* merge_units: begin func_00132910 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_910 { __int128 q; V_910() {} V_910(const V_910& o) { V_910* pd = this; const V_910* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } } };
static inline void VCp(V_910* pd, const V_910* ps) { asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
struct Node_910 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; V_910 m[4]; unsigned char dirty; char pad51[0x1D0 - 0x51]; };
struct Mdl_910 { char pad[0x14]; unsigned char hasSkel; char pad15[0xB]; Node_910* nodes; char pad24[4]; Node_910* root; };

extern "C" V_910 cSkeleton_GetBoneToWorldTranslation(Mdl_910* self, int idx)
{
    if (self->hasSkel) {
        Node_910* r = self->root;
        if (r->dirty) r->Update();
        V_910* mm = r->m;
        Node_910* n = &self->nodes[idx];
        if (n->dirty) n->Update();
        V_910 p; VCp(&p, &n->m[3]);
        V_910* pp = &p;
        asm {
            lqc2 vf8, 0x0(pp)
            lqc2 vf4, 0x0(mm)
            lqc2 vf5, 0x10(mm)
            lqc2 vf6, 0x20(mm)
            lqc2 vf7, 0x30(mm)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(pp)
        }
        return *pp;
    }
    Node_910* r = self->root;
    if (r->dirty) r->Update();
    return r->m[3];
}
static inline void merge_flush_func_00132910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132910 */

/* merge_units: begin func_00132A30 */
#pragma push /* merge_units */
void* cSKM_GOBJ_GetSkeleton_void(char* self) {
    return self + 11856;
}
static inline void merge_flush_func_00132A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132A30 */

/* merge_units: begin func_00132A40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct AlEq_c { char c; };
struct AlPred_c { AlEq_c op; void** ref; AlPred_c(const AlEq_c& e, void** r) : op(e), ref(r) {} };

extern "C" {
void cMemMan_Deallocate(int pool, void* p, const char* file, int line);
void nGobjManager_RemoveGOBJ(void*);
void cTargetManager_RemoveGobj(void*, void*);
void cSystem_ActualScheduleDelete(void*, float);
void* GetSceneManager(void);
void cLList_cScenePtr_Clear(void*);
extern void std_list_imp_voidPtr_remove_if(int* list, AlPred_c pred);
extern char D_0049A890[];
extern char g_TargetVisMgr[];
}

struct World132A40 {
    char pad[0xC0];
    void* c0;
    int list;
    char padc8[8];
    void* d0;
    void* d4;
};

static inline void Erase_c(int* l, void** r) { AlEq_c eq; std_list_imp_voidPtr_remove_if(l, AlPred_c(eq, r)); }
extern "C" void cGameSystem_DestroyPlayerCameraAndScene(World132A40* w)
{
    void* p;
    Erase_c(&w->list, &w->c0);
    cTargetManager_RemoveGobj(g_TargetVisMgr, w->c0);
    nGobjManager_RemoveGOBJ(w->c0);
    nGobjManager_RemoveGOBJ(w->d4);
    if (w->c0) {
        cSystem_ActualScheduleDelete(w->c0, 0.1f);
        w->c0 = 0;
    }
    if (w->d4) {
        cSystem_ActualScheduleDelete(w->d4, 0.1f);
        w->d4 = 0;
    }
    p = w->d0;
    if (p) {
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_0049A890, 0x563);
        }
        cLList_cScenePtr_Clear(GetSceneManager());
    }
}
static inline void merge_flush_func_00132A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132A40 */
