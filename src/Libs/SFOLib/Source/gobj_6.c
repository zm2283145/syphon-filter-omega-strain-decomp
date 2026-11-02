/*
 * Libs/SFOLib/Source/gobj: 11 files, 003CE750-003CEF20
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

/* merge_units: begin func_003CEF20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CEF20 { virtual int v0(...); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(...); };
extern "C" {
int cMemMan_Deallocate(...);                     
int cSystemContainer_dtor(...);                         
int operator_delete(...);                          
extern char D_004BD228;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_NextFrame();
#if 0 /* merge_units */
extern "C" void cGOBJ_CriticalNextFrame();
#endif /* merge_units */

extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
#if 0 /* merge_units */
extern "C" void cGOBJ_Activate();
#endif /* merge_units */

extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cGOBJ_getSOBJClassId();
extern "C" void cGOBJ_ScriptHandleMessage();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
extern "C" void func_00140E90();
extern "C" void cGOBJ_GetHealthState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void cGOBJ_GetTargetPosition();
extern "C" void cGOBJ_GetLosPosition();
extern "C" void cGOBJ_HasHeadset();
extern "C" void cGOBJ_SetStatus();
extern "C" void cGOBJ_GetStatus();
extern "C" void cGOBJ_GetChildList_void();
extern "C" void cGOBJ_GetChildList_void_2();
extern "C" void cGOBJ_ScaleBBox();
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGOBJ_GetTransform_ForFloorTravel();
extern "C" void cGOBJ_GetCameraCollisionReferencePoint();
extern "C" void cGOBJ_GetTransform_ForCameraTracking();
extern "C" void cGOBJ_GetTransform_ForTeleporting();
extern "C" void cGOBJ_GetCenterOfMass();
extern "C" void cGOBJ_GetActivationPoint();
extern "C" void cGOBJ_v35();
extern "C" void cGOBJ_GetMatrix();
extern "C" void cGOBJ_SetTranslation_ResetPhysics();
extern "C" void cGOBJ_SetRotation_ResetPhysics();
extern "C" void cGOBJ_SetTransform_ResetPhysics();
extern "C" void cGOBJ_ApplyTranslation();
extern "C" void cGOBJ_ApplyLocalRotation();
extern "C" void cGOBJ_ApplyTransform();
extern "C" void cGOBJ_SetTranslation();
extern "C" void cGOBJ_SetRotation();
extern "C" void cGOBJ_SetTransform();
#if 0 /* merge_units */
extern "C" void cGOBJ_Deactivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_NetDeactivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_NetActivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_Render();
#endif /* merge_units */
#define cGOBJ_Render() (cGOBJ_Render()) /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_Load();
#endif /* merge_units */
#define cGOBJ_Load() (cGOBJ_Load()) /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_Init();
#endif /* merge_units */
#define cGOBJ_Init() (cGOBJ_Init()) /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_ProcessMessage();
#endif /* merge_units */
#define cGOBJ_ProcessMessage() (cGOBJ_ProcessMessage()) /* merge_units */

#if 0 /* merge_units */
extern "C" void cGOBJ_HandleMessage();
#endif /* merge_units */

extern void * const D_004DFF50[];
extern unsigned char g_ProfileLockEnabled;
typedef struct { int f0; char p4[68]; unsigned char f48; char p49[7]; int f50; int f54; int f58; } PS0_003CEF20;
}
extern "C" char * cGOBJ_dtor(PS0_003CEF20 *arg0, long long arg1) {
    void **temp_a0;
    void **temp_s2;
    void **temp_s2_2;

    if (arg0 != NULL) {
        arg0->f0 = (int)(&(*(char*)D_004DFF50));
        temp_s2 = (void **)(arg0->f50);
        if (temp_s2 != NULL) {
            if (arg0->f48 != 0) {
                {
                    AllocGuard g;
                ((VC003CEF20 *)(temp_s2))->v0(-1);
                cMemMan_Deallocate(0, temp_s2, &D_004BD228, 0x174);
                }
                arg0->f48 = 0U;
            }
            arg0->f50 = NULL;
        }
        temp_a0 = (void **)(arg0->f58);
        if (temp_a0 != NULL) {
            ((VC003CEF20 *)(temp_a0))->v33(0);
            arg0->f58 = NULL;
        }
        temp_s2_2 = (void **)(arg0->f54);
        if (temp_s2_2 != NULL) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, temp_s2_2, &D_004BD228, 0x210);
            }
            arg0->f54 = NULL;
        }
        cSystemContainer_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (char *)(arg0);
}
void * const D_004DFF50[68] = { (void*)0x0, (void*)0x0, (void*)cGOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
#undef cGOBJ_Render /* merge_units */
#undef cGOBJ_Load /* merge_units */
#undef cGOBJ_Init /* merge_units */
#undef cGOBJ_ProcessMessage /* merge_units */
static inline void merge_flush_func_003CEF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CEF20 */

/* merge_units: begin func_003CF0E0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ constructor.
 */


#if 0 /* merge_units */
extern char D_004DFF50[];   /* cGOBJ vtable */
#endif /* merge_units */
#define D_004DFF50 ((char*)&D_004DFF50) /* merge_units */


extern void cSystemContainer_ctor_cObjectIdR(cGOBJ* self, int* desc);

cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3) {
    cSystemContainer_ctor_cObjectIdR(self, desc);
    self->vtable = D_004DFF50;
    self->unk2C = 1;
    self->unk2D = 0;
    self->unk2E = 0;
    self->unk2F = 0;
    self->unk30 = -1;
    self->unk38 = 128;
    self->unk3C = 0;
    self->unk40 = 0;
    self->darkness = 0;
    self->unk48 = 0;
    self->unk49 = a2;
    self->unk4C = *a3;
    self->unk50 = 0;
    self->unk54 = 0;
    self->attached = 0;
    self->unk5C = 0;
    self->unk10 = *desc;
    return self;
}
#undef D_004DFF50 /* merge_units */
static inline void merge_flush_func_003CF0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF0E0 */

/* merge_units: begin func_003CF190 */
#pragma push /* merge_units */
typedef struct C3FtNode { struct C3FtNode* left; struct C3FtNode* right; int pad; int key; } C3FtNode;
typedef struct { int pad; C3FtNode* root; } C3FtTree;
extern C3FtNode* FrameTree_Insert(C3FtTree* t, C3FtNode* parent, unsigned char left, unsigned char leftmost, int* key);
void FrameTree_Find(C3FtNode** out, C3FtTree* t, int* key)
{
    C3FtNode* parent = (C3FtNode*)&t->root;
    C3FtNode* n = t->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (n != 0) {
        parent = n;
        if (*key < n->key) {
            n = n->left;
            left = 1;
        } else {
            n = n->right;
            left = 0;
            leftmost = 0;
        }
    }
    *out = FrameTree_Insert(t, parent, left, leftmost, key);
}
static inline void merge_flush_func_003CF190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF190 */
