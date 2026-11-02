/*
 * SFOGame/Source/GameGOBJ: 8 files, 00219050-00219730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00219050 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Elem16* std_vector_cVector_opIndex(Elem16Vec* v, int i) {
    return &v->data[i];
}

int func_00219060(Elem16Vec* v) {
    return v->count;
}
static inline void merge_flush_func_00219050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219050 */

/* merge_units: begin func_00219070 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "gobj_v07_register.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_v06_update.h"
#pragma pop

#pragma cplusplus on
typedef struct Obj_00219070 { char pad[0xC]; int id; } Obj_00219070;
typedef struct { char d[0x9C]; } Str_00219070;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00219070 s78;
    Str_00219070 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_00219070;
typedef struct LiftMsg_00219070 { void* vtable; char base[0x20]; int kind; int floor; int from; int to; char pad34[0xC]; } LiftMsg_00219070;
typedef struct Notice_00219070 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00219070;
typedef struct Node_00219070 { char pad[0x49]; unsigned char type; } Node_00219070;
struct Handler_00219070 { virtual void v0(); virtual void Receive(void* ev); };
typedef struct Path_00219070 {
    char pad0[0x64]; Handler_00219070* handler; char pad68[8]; int count; char pad74[8]; Node_00219070** nodes;
    char pad80[0xDC - 0x80]; unsigned char bDC; char padDD[3]; int fE0; void* preset;
} Path_00219070;
extern int g_TriggerMsgKey;
extern "C" {
extern char D_004F5450[];
extern char D_004DAE90[];
extern char D_004DAF10[];
extern char D_004DAE30[];
extern char g_Game[];
extern int D_0055D4D8;
extern int g_TeleportMsgClass;
extern int* cMessage_Name(void* ev);
extern void cMessage_ctor_cMessageNameR(void* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void cPlaySoundMsg_ctor_cSndFxR(Snd_00219070* e, void* preset, void* owner);
#if 0 /* merge_units */
extern void cFileMan_dtor(Str_00219070* s, int flag);
#endif /* merge_units */
void cFileMan_dtor(void* p, int flag); /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */


extern int cGOBJ_HandleMessage(Path_00219070* self, void* ev);
}
static inline int ObjId_00219070(Obj_00219070* o) { return o ? o->id : 0; }
#pragma opt_strength_reduction off
extern "C" int cPathedGOBJ_HandleMessage(Path_00219070* self, void* ev)
{
    int t = *cMessage_Name(ev);
    if (t == g_TriggerMsgKey) {
        int i;
        Snd_00219070 s;
        LiftMsg_00219070 msg;
        Notice_00219070 n;
        {
            self->bDC = 0;
            cMessage_ctor_cMessageNameR(&n, D_004F5450);
            n.vtable = D_004DAE90;
            n.kind = 1;
            n.arg = -1;
            QueueMessage_cMessageR_cSystemP_int(&n, self, 0);
            n.vtable = D_004DAE90;
            cMessage_dtor(&n, 0);
        }
        self->fE0 = 0;
        if (self->preset) {
            cPlaySoundMsg_ctor_cSndFxR(&s, self->preset, self);
            s.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&s, g_Game, 1);
            s.vt = D_004DAE30;
            cFileMan_dtor(&s.s114, -1);
            cFileMan_dtor(&s.s78, -1);
            cMessage_dtor(&s, 0);
        }
        for (i = 0; i < self->count; i++) {
            if (self->nodes[i]->type == 0xB) {
                LiftMsg_00219070* m = &msg;
                cMessage_ctor_cMessageNameR(m, &g_TriggerMsgKey);
                msg.vtable = D_004DAF10;
                msg.kind = 0;
                msg.floor = 0;
                m->to = ObjId_00219070(0);
                m->from = ObjId_00219070(0);
                QueueMessage_cMessageR_cSystemP_int(&msg, self->nodes[i], 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
        }
        return 1;
    }
    t = *cMessage_Name(ev);
    if (t == D_0055D4D8 || (t = *cMessage_Name(ev), t == g_TeleportMsgClass)) {
        Handler_00219070* h = self->handler;
        if (h)
            h->Receive(ev);
        return cGOBJ_HandleMessage(self, ev);
    }
    return cGOBJ_HandleMessage(self, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00219070(void) {}
#undef cFileMan_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219070 */

/* merge_units: begin func_002192F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 7: notify attached object, update, register. */
DEFINE_GOBJ_V07_REGISTER(cPathedGOBJ_NetDeactivate)
static inline void merge_flush_func_002192F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002192F0 */

/* merge_units: begin func_00219350 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 6: notify attached object, update, call slot 47. */
DEFINE_GOBJ_V06_UPDATE(cPathedGOBJ_NetActivate)
static inline void merge_flush_func_00219350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219350 */

/* merge_units: begin func_002193B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Path: only the slots used here are named (vtable offset in comments). */
struct Path {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(); /* +0x60 */
};

typedef struct cPathedGOBJ { char pad[0x64]; Path* path; /* +0x64 */ } cPathedGOBJ;

extern char g_TargetVisMgr[];
extern "C" void cGOBJ_Deactivate(cPathedGOBJ* self, void* arg);
#if 0 /* merge_units */
extern "C" void cTargetManager_RemoveGobj(void* list, cPathedGOBJ* obj);
#endif /* merge_units */
#define cTargetManager_RemoveGobj(a0, a1) (cTargetManager_RemoveGobj((a0), (GobjV07 *)(a1))) /* merge_units */




/* Notifies the path (virtual +0x60), runs the base handler, then cTargetManager_RemoveGobj(g_TargetVisMgr, self). */
extern "C" void cPathedGOBJ_Deactivate(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    cGOBJ_Deactivate(self, arg);
    cTargetManager_RemoveGobj(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002193B0(void) {}
#undef cTargetManager_RemoveGobj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002193B0 */

/* merge_units: begin func_00219410 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
};

struct cPathedGOBJ_00219410 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E();
    virtual void MethodC4(); /* +0xC4 */
    char pad04[0x64 - 4];
    Door* door; /* +0x64 */
};

extern "C" void cGOBJ_Activate(cPathedGOBJ_00219410* self, void* arg);

/* Notifies the door object (+0x64, virtual +0x5C), runs cGOBJ_Activate and virtual +0xC4. */
extern "C" void cPathedGOBJ_Activate(cPathedGOBJ_00219410* self, void* arg)
{
    if (self->door)
    self->door->Method5C();
    cGOBJ_Activate(self, arg);
    self->MethodC4();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00219410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00219410 */

/* merge_units: begin func_00219470 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004A4550[];
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
#if 0 /* merge_units */
extern "C" void cPathedGOBJ_HandleMessage();
#endif /* merge_units */


extern "C" void cPathedGOBJ_ScriptHandleMessage();
extern "C" void cPathedGOBJ_NextFrame();
#if 0 /* merge_units */
extern "C" void cPathedGOBJ_NetActivate();
#endif /* merge_units */


#if 0 /* merge_units */
extern "C" void cPathedGOBJ_NetDeactivate();
#endif /* merge_units */


extern "C" void cPathedGOBJ_getSOBJClassId();
#if 0 /* merge_units */
extern "C" void cPathedGOBJ_Activate();
#endif /* merge_units */


#if 0 /* merge_units */
extern "C" void cPathedGOBJ_Deactivate();
#endif /* merge_units */


extern "C" void cPathedGOBJ_InitNetwork();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
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
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGameGOBJ_GetBBox();
extern "C" void cGameGOBJ_GetTargetPriority();
extern "C" void cGameGOBJ_SetParent();
extern "C" void cGameGOBJ_Render();
extern "C" void cGameGOBJ_CriticalNextFrame();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void cGameGOBJ_NetEnable();
extern "C" void cGameGOBJ_NetDisable();
extern "C" void cGameGOBJ_GetCollisionModel();
extern "C" void cGameGOBJ_IsNetworked();
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
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cGOBJ_ProcessMessage();
extern void * const D_004DB280[];
extern unsigned char g_IsMultiplayer;
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void cGameGOBJ_dtor(void* p, int flag);
void std_vector_deleter_cVector_dtor(void* p, int flag);
int func_00211DA0(void);
#if 0 /* merge_units */
void std_vector_float_dtor(void* p, int flag);
#endif /* merge_units */
void* std_vector_float_dtor(void* self, short deleteFlag); /* merge_units */
#define std_vector_float_dtor(a0, a1) ((void)std_vector_float_dtor((a0), (short)(a1))) /* merge_units */

void std_vector_deleter_cQuaternion_dtor(void* p, int flag);
void NetFreeObject(int a);
void cFileMan_dtor(void* p, int flag);
void operator_delete(void* p);
}
struct E_00219470 { char pad[0x48]; char m48[0xE4 - 0x48]; char mE4[4]; };
struct D_00219470s { char pad[0xC]; unsigned char c; };
struct S_00219470 { void* vt; char pad4[0x90]; char m94[0x10]; char mA4[0x10]; char mB4[0x1C]; D_00219470s* pD0; char padd4[0x10]; E_00219470* pE4; };
static inline void Free_00219470(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004A4550, line); }
static inline void M3_0021C090(void* m) { if (m) { if (m) { if (m) std_vector_deleter_cQuaternion_dtor(m, 0); } } }
static inline void M3_001810D0(void* m) { if (m) { if (m) { if (m) std_vector_deleter_cVector_dtor(m, 0); } } }
extern "C" S_00219470* cPathedGOBJ_dtor(S_00219470* self, short flag)
{
    if (self) {
        void* m;
        E_00219470* e;
        D_00219470s* d;
        self->vt = ((char*)D_004DB280);
        e = self->pE4;
        if (e) {
            AllocGuard g;
            if (e) {
                cFileMan_dtor(e->mE4, -1);
                cFileMan_dtor(e->m48, -1);
            }
            cMemMan_Deallocate(0, e, D_004A4550, 0x266);
        }
        if (g_IsMultiplayer) {
            d = self->pD0;
            if (d) {
                if (d->c) NetFreeObject(func_00211DA0());
                else Free_00219470(d, 0xB83);
                self->pD0 = 0;
            }
        } else {
            d = self->pD0;
            if (d) {
                Free_00219470(d, 0x270);
                self->pD0 = 0;
            }
        }
        m = self->mB4; if (m) std_vector_float_dtor(m, -1);
        M3_0021C090(self->mA4);
        M3_001810D0(self->m94);
        cGameGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB280[72] = { (void*)0x0, (void*)0x0, (void*)cPathedGOBJ_dtor, (void*)cPathedGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGameGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cPathedGOBJ_NetActivate, (void*)cPathedGOBJ_NetDeactivate, (void*)cGameGOBJ_NetEnable, (void*)cGameGOBJ_NetDisable, (void*)cSystem_IsDeliverable, (void*)cPathedGOBJ_getSOBJClassId, (void*)cPathedGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cPathedGOBJ_NextFrame, (void*)cGameGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGameGOBJ_Render, (void*)cPathedGOBJ_Activate, (void*)cPathedGOBJ_Deactivate, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGameGOBJ_GetCollisionModel, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGameGOBJ_GetTargetPriority, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cPathedGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cGameGOBJ_SetParent, (void*)0x0, (void*)0x0, (void*)0x0 };
#undef std_vector_float_dtor /* merge_units */
static inline void merge_flush_func_00219470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219470 */

/* merge_units: begin func_00219730 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_float_dtor)
static inline void merge_flush_func_00219730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00219730 */
