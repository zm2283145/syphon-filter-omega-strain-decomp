/*
 * Libs/SFOLib/Source/gobj: 8 files, 003CE750-003CEA10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CE750 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
class C4C3CE {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void PreLogic();
};
struct C4Act3CE { char pad[0x58]; C4C3CE* ctl; };
extern "C" void cGOBJ_CriticalNextFrame(C4Act3CE* a) {
    if (a->ctl) a->ctl->PreLogic();
}
static inline void merge_flush_func_003CE750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CE750 */

/* merge_units: begin func_003CE790 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Attachment: only the slots used here are named (vtable offset in comments). */
struct Attachment {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10();
    virtual void Method4C(); /* +0x4C */
};

typedef struct Owner {
    char pad[0x2D];
    unsigned char active;   /* +0x2D */
    char pad2E[0x58 - 0x2E];
    Attachment* attachment; /* +0x58 */
} Owner;

/* Clears the active flag and calls the attachment's virtual +0x4C, if any. */
extern "C" void cGOBJ_Deactivate(Owner* self)
{
    self->active = 0;
    if (self->attachment)
        self->attachment->Method4C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE790 */

/* merge_units: begin func_003CE7D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Clears the active flag and calls its virtual at vtable+0x4C, if any. */
extern "C" void cGOBJ_NetDeactivate(Owner* self)
{
    self->active = 0;
    if (self->attachment)
        self->attachment->Method4C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE7D0 */

/* merge_units: begin func_003CE810 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
class C3CE810 { public: VPAD16(a) virtual void f(); };
struct O3CE810 { char pad[0x2D]; unsigned char b2D; char pad2[0x2A]; C3CE810* m; };
extern "C" void cGOBJ_NetActivate(O3CE810* self)
{
    self->b2D = 1;
    C3CE810* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE810 */

/* merge_units: begin func_003CE850 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma cplusplus on
struct V4_850 { float x, y, z, w; V4_850() {} } __attribute__((aligned(16)));
class Obj_850 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V4_850 GetPos(int);
};
extern "C" {
Obj_850* nGobjManager_GetPlayer(void);
Obj_850* cNetObj_GetPlayer(int);
}
static inline void VSub_850(V4_850* a, V4_850* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline float LenSq_850(V4_850* a) {
    int rv0;
    float ret;
    asm { mtc1 $zero, ret } /* pins retail's dead zero-init of ret (documented idiom) */
    asm {
        lqc2 vf1, 0x0(a)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
extern "C" Obj_850* cGOBJ_GetClosestPlayer(Obj_850* self, float* outDist)
{
    Obj_850* best = nGobjManager_GetPlayer();
    float bestD = 1e8f;
    int i = 0;
    goto test;
loop:
    {
        Obj_850* p = cNetObj_GetPlayer(i);
        if (p) {
            V4_850 a = self->GetPos(-1);
            V4_850 b = p->GetPos(-1);
            { V4_850* pa = &a; V4_850* pb = &b; VSub_850(pa, pb); }
            float d = LenSq_850(&a);
            if (d < bestD) {
                bestD = d;
                best = p;
            }
        }
    }
    i++;
test:
    if ((unsigned)i != 4) goto loop;
    if (outDist)
        *outDist = bestD;
    return best;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE850 */

/* merge_units: begin func_003CE980 */
#pragma push /* merge_units */
#include "gobj_types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Component {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Activate(); /* +0x48 */
};

typedef struct Owner_003CE980 {
    char pad[0x2C];
    unsigned char enabled;  /* +0x2C */
    unsigned char active;   /* +0x2D */
    char pad2E[0x58 - 0x2E];
    Component* component; /* +0x58 */
} Owner_003CE980;

/* Marks the object active (+0x2D) and, if enabled (+0x2C), activates its component (+0x58, virtual +0x48). */
extern "C" void cGOBJ_Activate(Owner_003CE980* self)
{
    Component* component;
    self->active = 1;
    component = self->component;
    if (component && self->enabled)
    component->Activate();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE980 */

/* merge_units: begin func_003CE9D0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */


void cGOBJ_Render(void) {
}

void cGOBJ_Load(void) {
}

void cGOBJ_Init(void) {
}

void cGOBJ_ProcessMessage(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE9D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE9D0 */

/* merge_units: begin func_003CEA10 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QA(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QS(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
static inline void JC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); void* xx = d; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* m) { int t; void* p = m; asm { .set noreorder; sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p); .set reorder } }
static inline void VZ(void* d) { asm { .set noreorder; sq zero, 0(d); .set reorder } }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); void* xx = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
    void SetAdd(const V& a0, const V& b0);
} __attribute__((aligned(16)));
static inline void SetAddI_(V* self, const V& a0, const V& b0) { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory"); void* xx = self; const V* s = &r; V* d = self; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
inline void V::SetAdd(const V& a0, const V& b0) { SetAddI_(this, a0, b0); }

static inline V Add(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%2)" : : "r"(&a0), "r"(&b0), "r"(&r) : "memory");
    return r;
}
static inline V AddV(const V& a0, V b0) { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory"); return r; }
struct M34 { V r[3]; V t; };
struct M44;
static inline void MulRot(M44* d, M44* s, M44* r);
struct M44 {
    __int128 q[4];
    M44() {}
    void Rot(M44* r) { M44* p = this; MulRot(p, p, r); }
    M44* RotR(M44* r) { M44* p = this; MulRot(p, p, r); return p; }
};
static inline void MulRot(M44* d, M44* s, M44* r)
{
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddz.xyzw vf12, vf6, vf8z; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddz.xyzw vf13, vf6, vf9z; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddz.xyzw vf14, vf6, vf10z; vmove.xyzw vf15, vf7; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(s), "r"(r) : "memory");
}
extern "C" void cMatrix_GetRotation(M44* d, const M34* s);
struct Xf {
    virtual void v0();
    virtual void Set34(M34* m);
    virtual void SetMtx(M44* m);
    virtual void SetPos(const V& p);
    VPAD16(a)
    virtual void Update();
    char pad04[0xC];
    M34 m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
    const V& Pos() { Sync(); return m.t; }
};
struct MoverH {
    VPAD16(a) VPAD2(b)
    virtual void Move(V* d);
};
struct NodeH { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; };
struct Msg { char pad[0x24]; char kind; char pad25[0xB]; M34 m; };
struct MsgClass { int id; };
extern "C" MsgClass* cMessage_Name(Msg* m);
extern "C" signed char D_004E1D88;
extern "C" V D_004E1D90;
extern "C" MsgClass D_0055D4D8;
extern "C" MsgClass g_TeleportMsgClass;
extern "C" MsgClass g_cEnableMsgClass;
extern "C" MsgClass g_cDisableMsgClass;
struct Obj;
extern "C" int cSystemContainer_HandleMessage(Obj* o, Msg* m);
struct Obj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void OnEnable(int f);
    virtual void OnDisable(int f);
    char pad04[0x28];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x21];
    Xf* xf;
    NodeH* NodeH;
    MoverH* MoverH;
    bool Active() { bool r = false; if (b2D && b2C) r = true; return r; }
    bool Off() { return b2E; }
    bool Vis() { return Off() == false; }
    bool NotOff() { return !Off(); }
    bool Live() { bool r = false; if (Active() && (Off() ^ 1)) r = true; return r; }
};

static inline void Case4_3CEA10(Obj* obj, Msg* msg) {
            M44 b;
            M44 a;
            cMatrix_GetRotation(&a, &msg->m);
            Xf* x = obj->xf;
            x->Sync();
            cMatrix_GetRotation(&b, &x->m);
            obj->xf->SetMtx(b.RotR(&a));
}
extern "C" int cGOBJ_HandleMessage(Obj* obj, Msg* msg)
{
    int t;
    t = cMessage_Name(msg)->id;
    if (t == D_0055D4D8.id || (t = cMessage_Name(msg)->id, t == g_TeleportMsgClass.id)) {
        if (obj->xf) {
        if (!D_004E1D88) {
            D_004E1D90.x = 0;
            D_004E1D88 = 1;
            D_004E1D90.y = 0;
            D_004E1D90.z = 0;
            D_004E1D90.w = 0;
        }
        V delta;
        { const V* s = &D_004E1D90; V* d = &delta; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(q) : "r"(s), "r"(d) : "memory"); }
        switch ((unsigned char)msg->kind) {
        case 0:
            {
            V p = msg->m.t;
            obj->xf->SetPos(p);
            }
            break;
        case 1: {
            M44 a;
            cMatrix_GetRotation(&a, &msg->m);
            obj->xf->SetMtx(&a);
            break;
        }
        case 2:
            obj->xf->Set34(&msg->m);
            break;
        case 3: {
            V np;
            V d = msg->m.t;
            np.SetAdd(obj->xf->Pos(), d);
            obj->xf->SetPos(np);
            delta = V(msg->m.t);
            break;
        }
        case 4:
            Case4_3CEA10(obj, msg);
            break;
        }
        t = cMessage_Name(msg)->id;
        if (t == g_TeleportMsgClass.id) {
            if (obj->NodeH) {
                Xf* x = obj->xf;
                if (x) {
                    NodeH* n; if (x->b50) x->Update(); void* s; s = &x->m; n = obj->NodeH; n->flag = 0; void* d = &n->m; GQR(&n->m, s); void* xx = &n->xf; UM(&n->xf); VZ(&n->v90);
                    VZ(&n->vA0);
                }
            }
            if (obj->MoverH) obj->MoverH->Move(&delta);
        }
        return 1;
        }
        return 0;
    }
    t = cMessage_Name(msg)->id;
    if (t == g_cEnableMsgClass.id) {
        if (!obj->Live()) obj->OnEnable(1);
        obj->b2C = 1;
        return 1;
    }
    t = cMessage_Name(msg)->id;
    if (t == g_cDisableMsgClass.id) {
        if (obj->Live()) obj->OnDisable(1);
        obj->b2C = 0;
        return 1;
    }
    return cSystemContainer_HandleMessage(obj, msg);
}
static inline void merge_flush_func_003CEA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CEA10 */
