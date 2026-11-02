/*
 * Libs/SFOLib/Source/gobj: 17 files, 003CC8E0-003CCF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CC8E0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC003CC8E0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); virtual int v25(...); };
extern "C" {

}
extern "C" int cGOBJ_Enemy(char * arg0, char * arg1) {
    int var_v0;
    void **temp_a0;
    void **temp_s0;

    temp_s0 = (void **)(F_(arg0, 0x58, int));
    var_v0 = -1;
    if (temp_s0 != NULL) {
        temp_a0 = (void **)(F_(arg1, 0x58, int));
        if (temp_a0 != NULL) {
            var_v0 = ((VC003CC8E0 *)(temp_a0))->v24();
        }
        var_v0 = ((VC003CC8E0 *)(temp_s0))->v25(var_v0) & 0xFF;
    }
    return var_v0 != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC8E0 */

/* merge_units: begin func_003CC950 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CC950 { public: VPAD16(p0) VPAD8(p1)  virtual int f(); };
struct O003CC950 { char pad[0x58]; C003CC950* m; };
extern "C" int cGOBJ_Team(O003CC950* self)
{
    C003CC950* m = self->m;
    int r = -0x1;
    if (m)
        r = m->f();
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC950 */

/* merge_units: begin func_003CC990 */
#pragma push /* merge_units */
typedef struct ValueMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char kind;   /* 0x20 */
    char pad21[3];
    unsigned char flag;   /* 0x24 */
    char pad25[3];
    int id;               /* 0x28 */
    int value;            /* 0x2C */
} ValueMsg;

typedef struct ValueObj {
    char pad00[0xC];
    int id;               /* 0x0C */
    char pad10[0x30];
    float value;          /* 0x40 */
} ValueObj;

extern unsigned char g_IsMultiplayer;
extern char D_00582750[];
extern char D_004E0EE0[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(ValueMsg* msg, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(ValueMsg* msg, void* target, int flags);
#endif /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int); /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(ValueMsg* msg, int flags);
#endif /* merge_units */
void cMessage_dtor(void*, int); /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Sets the value; in networked mode (unless silent) broadcasts it as message kind 4. */
void cGOBJ_SetHitpoints(ValueObj* obj, int value, int silent) {
    ValueMsg msg;
    obj->value = (float)value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_00582750);
        msg.flag = 0;
        msg.vtbl = D_004E0EE0;
        msg.id = obj->id;
        msg.kind = 4;
        msg.value = value;
        QueueMessage_cMessageR_cSystemP_int(&msg, obj, 0);
        msg.vtbl = D_004E0EE0;
        cMessage_dtor(&msg, 0);
    }
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_003CC990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC990 */

/* merge_units: begin func_003CCA40 */
#pragma push /* merge_units */
#include "vu0_ops.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0xA0]; V4 vA0; } C3_Y;
typedef struct { char pad[0x54]; C3_Y* p54; } C3_X;
typedef struct { char pad[0x5C]; C3_X* p5C; } C3_O;
C3_X* cGOBJ_IsOnMovingElevator(C3_O* o) {
    C3_X* x = o->p5C;
    if (x) {
        if (x->p54 && !VU0_IsZero4(&x->p54->vA0)) return x;
        return 0;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CCA40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CCA40 */

/* merge_units: begin func_003CCAC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class C3Vt3CC {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
};
struct C3Own3CC { char pad[0x58]; C3Vt3CC* child; };
extern "C" void cGOBJ_Die(C3Own3CC* o)
{
    if (o->child != 0) {
        o->child->v29();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CCAC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CCAC0 */

/* merge_units: begin func_003CCB00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_3CCB00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual int IsGod(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void OnHit(int attacker, int dmg); };
struct SelfV_3CCB00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual unsigned char State(); virtual void Kill(int dmg, int attacker, unsigned char p2, int p3, int p6); };
struct Self_3CCB00 : SelfV_3CCB00 { char pad4[0x10]; unsigned char b14; char pad15[0x2B]; float health; char pad44[0x14]; Ctl_3CCB00* ctl; };
typedef struct { void* vt; char base[0x1C]; unsigned char kind; char pad21[3]; int dmg; int attacker; char p3; char p2; char flag; char pad2F; } Msg_3CCB00;
extern "C" {
extern char D_004E08A0[];
extern char g_MsgLibDamageRequestKey[];
extern unsigned char D_005721C0;
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg_3CCB00* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(Msg_3CCB00* m, void* target, int f);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void cMessage_dtor(Msg_3CCB00* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


}
static inline unsigned char IsGod_3CCB00(Self_3CCB00* self)
{
    unsigned char r = 0;
    Ctl_3CCB00* c = self->ctl;
    if (c && c->IsGod()) r = 1;
    return r;
}
extern "C" int cGOBJ_ReceiveDamage(Self_3CCB00* self, int attacker, int p2, int p3, int p4, int flag, int p6, float dmg)
{
    if (!attacker) return 0;
    if (!(self->health <= 0.0f)) {
        int idmg;
        Msg_3CCB00 m;
        if (!g_IsMultiplayer || !IsGod_3CCB00(self)) self->health = self->health - dmg;
        cMessage_ctor_cMessageNameR(&m, g_MsgLibDamageRequestKey);
        idmg = (int)dmg;
        m.attacker = attacker;
        m.vt = D_004E08A0;
        m.p3 = p3;
        m.p2 = p2;
        m.dmg = idmg;
        m.flag = 1;
        if (g_IsMultiplayer) {
            if (self->ctl == 0 && flag == 0) {
                m.kind = 2;
                m.flag = 0;
                QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
            } else if ((self->b14 && self->ctl) || (!self->ctl && flag)) {
                m.kind = 2;
                QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
            }
        } else {
            QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        }
        if ((int)self->health <= 0) {
            self->health = 0.0f;
            self->Kill(idmg, attacker, p2, p3, p6);
        } else if (self->ctl && attacker != (int)self) {
            self->ctl->OnHit(attacker, idmg);
        }
        m.vt = D_004E08A0;
        cMessage_dtor(&m, 0);
    } else if (g_IsMultiplayer) {
        int v = g_IsMultiplayer ? D_005721C0 : 1;
        if (!v && !self->ctl && !flag) {
            Msg_3CCB00 m2;
            cMessage_ctor_cMessageNameR(&m2, g_MsgLibDamageRequestKey);
            m2.attacker = attacker;
            m2.vt = D_004E08A0;
            m2.p3 = p3;
            m2.p2 = p2;
            m2.dmg = (int)dmg;
            m2.flag = 1;
            m2.kind = 2;
            m2.flag = 0;
            QueueMessage_cMessageR_cSystemP_int(&m2, self, 0);
            m2.vt = D_004E08A0;
            cMessage_dtor(&m2, 0);
        }
    }
    return self->State() == 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CCB00(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCB00 */

/* merge_units: begin func_003CCE30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct F6Actor;
struct F6Comp { virtual void Destroy(int f); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void Attach(F6Actor* a); };
struct F6Actor { char pad[0x58]; F6Comp* comp; };
extern "C" {
}
static inline void F6Delete(F6Comp* p)
{
    AllocGuard g;
    p->Destroy(-1);
    cMemMan_Deallocate(0, p, "gobj.cc", 0x291);
}
extern "C" void cGOBJ_AttachController(F6Actor* a, F6Comp* c)
{
    if (a->comp) {
        if (a->comp) {
            F6Delete(a->comp);
            a->comp = 0;
        }
    }
    a->comp = c;
    if (a->comp) a->comp->Attach(a);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CCE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CCE30 */

/* merge_units: begin func_003CCF20 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Sets cGOBJ +0x30 (initialized to -1 by the constructor). */
void cGobjController_SetGobj(cGOBJ* self, int value) {
    self->unk30 = value;
}
static inline void merge_flush_func_003CCF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCF20 */

/* merge_units: begin func_003CCF30 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { 
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */
extern char D_004BD228[]; }
class C3CCF30 { public: virtual void Destroy(int flags); };
struct O3CCF30 { char pad[0x58]; C3CCF30* m; };
extern "C" void cGOBJ_DeleteController(O3CCF30* self)
{
    C3CCF30* m = self->m;
    if (m) {
        {
            AllocGuard g;
            m->Destroy(-1);
            cMemMan_Deallocate(0, m, D_004BD228, 0x291);
        }
        self->m = 0;
    }
}
static inline void merge_flush_func_003CCF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCF30 */

/* merge_units: begin func_003CCFF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "node_world_q4.h"
extern "C" MtxQ4 g_IdentityMatrix;
extern "C" MtxQ4 cGOBJ_GetTransform_ForFloorTravel(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CCFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCFF0 */

/* merge_units: begin func_003CD090 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "v4_asm_copy.h"
struct N_3CD420 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0x40 - 4];
    V4 pos;
    unsigned char dirty;
};
struct X_3CD420 { char pad[0x50]; N_3CD420* n; };
#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_GetCameraCollisionReferencePoint(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
static inline void merge_flush_func_003CD090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD090 */

/* merge_units: begin func_003CD110 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetTransform_ForCameraTracking(OwnerQ4* o, int* flag)
{
    *flag = 0;
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD110 */

/* merge_units: begin func_003CD1C0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetTransform_ForTeleporting(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD1C0 */

/* merge_units: begin func_003CD260 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
static inline V Add(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
static inline V Scale(V v, float s) {
    V c; __int128 t = 0; const V* pv = &v; V* q = &c;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(pv), "f"(s) : "memory");
    return c;
}
static inline V Xf(const V& in, M* m, V o = V()) {
    o = in;
    V* out = &o;
    asm {
        lqc2 vf8, 0x0(out)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(out)
    }
    return *out;
}
static inline V Zero() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
class ObjB {
public:
    virtual void f08(); virtual void f0C(); virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual void f2C(); virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3C(); virtual void f40(); virtual void f44();
    virtual void f48(); virtual void f4C(); virtual void f50(); virtual void f54(); virtual void Update();
};
class Obj : public ObjB {
public:
    char pad4[0xC];
    M m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
};
class PB {
public:
    virtual void f08(); virtual void f0C(); virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual void f2C(); virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3C(); virtual void f40(); virtual void f44();
    virtual void f48(); virtual void f4C(); virtual void f50(); virtual void f54(); virtual void f58(); virtual void f5C(); virtual void f60(); virtual void f64();
    virtual void f68(); virtual void f6C(); virtual void f70(); virtual void f74(); virtual void f78(); virtual void f7C(); virtual void f80(); virtual void f84();
    virtual Box* GetBox();
};
class PathObj : public PB {
public:
    char pad4[0x45];
    unsigned char b49;
    char pad4a[6];
    Obj* p50;
    Box* SafeBox() { if (b49 != 14) return GetBox(); return 0; }
};
static inline V XfW(const V& in, M* m) { const V& i2 = in; return Xf(i2, m); }
static inline V Center(Box* b) { return Scale(Add(b->mn, b->mx), 0.5f); }
extern "C" V cGOBJ_GetCenterOfMass(PathObj* self)
{
    if (self->p50) {
        if (self->SafeBox()) {
            Obj* o = self->p50;
            o->Sync();
            M* m = &o->m;
            return XfW(V(Center(self->GetBox())), m);
        }
        Obj* o = self->p50;
        o->Sync();
        return o->m.r[3];
    }
    return Zero();
}
static inline void merge_flush_func_003CD260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD260 */

/* merge_units: begin func_003CD420 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_GetActivationPoint(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD420 */

/* merge_units: begin func_003CD4A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_v35(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD4A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD4A0 */

/* merge_units: begin func_003CD520 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetMatrix(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD520 */
