#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 q; V4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { F8Plc world; char pad20[0x30]; F8Plc local; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
extern V4* cQuaternion_opAssign(V4* d, V4* s);
extern V4* cVector_opAssign(V4* d, V4* s);
extern void* cQuatVec_Rotation(F8Plc* p);
extern void* cQuatVec_Translation(F8Plc* p);
extern void cQuatVec_Rotate(F8RootW* w, void* q);
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
