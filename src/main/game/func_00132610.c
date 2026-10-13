#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 q; V4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { F8Plc world; char pad20[0x30]; F8Plc local; char pad70[0x30]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* Root_Identity(void* self);
extern int Root_GetParent(F8Root* r);
extern V4* func_001325F0(V4* d, V4* s);
extern V4* Vec4_Copy(V4* d, V4* s);
extern void* Placement_GetQuat(F8Plc* p);
extern void* Placement_GetPosition(F8Plc* p);
extern void func_00132530(F8RootW* w, void* q);
extern void func_00132510(F8RootW* w, void* pos);
extern V4* func_00132840(V4* self);
extern void func_00132810(V4* a, V4* b, V4* c);
extern V4* func_00132800(V4* d, V4* s);
void Root_RefreshWorldCache(F8Root* r);
static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    func_001325F0(&d->q, &s->q);
    Vec4_Copy(&d->pos, &s->pos);
}
static inline F8Plc* ParentPlc_(F8Root* p)
{
    if (Root_GetParent(p)) {
        Root_RefreshWorldCache(p);
        return &Root_Identity(p)->world;
    }
    return &Root_Identity(p)->local;
}
static inline F8Plc* RootWorld_(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp = ParentPlc_(p);
            F8RootW* w;
            F8PlcCopy(&Root_Identity(r)->world, &Root_Identity(r)->local);
            w = Root_Identity(r);
            func_00132530(w, Placement_GetQuat(pp));
            func_00132510(w, Placement_GetPosition(pp));
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
void Root_RefreshWorldCache(F8Root* r)
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
        func_00132840(&t);
        func_00132810(&t, &pp->q, &r->world.q);
        func_00132800(&u, &t);
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
