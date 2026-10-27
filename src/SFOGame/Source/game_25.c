/*
 * SFOGame/Source/game: 3 files, 00132530-00132610
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

extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
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
extern V4* cQuaternion_ctor_void(V4* self);
extern void cQuaternion_VU0Multiply(V4* a, V4* b, V4* c);
extern V4* cQuaternion_ctor_cQuaternionR(V4* d, V4* s);
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
