/*
 * SFOGame/Source/hotbox: 7 files, 00171600-00171920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00171600 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
struct V4_1600 { __int128 q;
    V4_1600() {}
    V4_1600(const V4_1600& o) { const __int128* s = &o.q; __int128* d = &q; __int128 t; asm {  lq t, 0(s) } asm {  sq t, 0(d) } } };
struct M4_1600 { V4_1600 r[4];
    M4_1600() {}
    M4_1600(const M4_1600& o) { const __int128* s = &o.r[0].q; __int128* d = &r[0].q; __int128 qa, qb;
        asm { .set reorder;
            lq qa, 0x0(s)
            lq qb, 0x10(s)
            sq qa, 0x0(d)
            lq qa, 0x20(s)
            sq qb, 0x10(d)
            lq qb, 0x30(s)
            sq qa, 0x20(d)
            sq qb, 0x30(d)
        } } };
struct Trk_1600 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC]; M4_1600 mat; unsigned char active; };
typedef struct { char pad[0x14]; unsigned char on; char pad15[0x3B]; Trk_1600* trk; } Src_1600;
typedef struct { char pad[0x20]; Src_1600* src; } HT_1600;
extern "C" int* cMessage_Name(void* e);
extern "C" int D_005436B0;
extern "C" void cHotboxMan_Update(HT_1600* self, V4_1600 pos, int f);
static inline V4_1600 Trans_1600(M4_1600 m) { return m.r[3]; }
static inline V4_1600 TransR_1600(const M4_1600& m) { return m.r[3]; }
extern "C" int cHotboxMan_HandleMessage(HT_1600* self, void* e)
{
    int ty = *cMessage_Name(e);
    if (ty == D_005436B0) {
        Src_1600* s = self->src;
        if (s && s->on) {
            Trk_1600* t = s->trk;
            if (t->active) t->Update();
            M4_1600 m(t->mat);
            cHotboxMan_Update(self, TransR_1600(m), 0);
        }
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_00171600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171600 */

/* merge_units: begin func_001716E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "hotbox_types.h"

extern char D_004D9960[];  /* class table */
extern char D_004EE6C0[];
extern void cSystem_ctor(void* self, void* type);
extern void std_list_deleter_voidPtr_ctor_void(void* self);

HotboxReceiver* cHotboxMan_ctor(HotboxReceiver* self, int unk20) {
    cSystem_ctor(self, D_004EE6C0);
    self->vtable = D_004D9960;
    std_list_deleter_voidPtr_ctor_void(self->unk28);
    self->unk20 = unk20;
    self->unk24 = 0;
    return self;
}
static inline void merge_flush_func_001716E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001716E0 */

/* merge_units: begin func_00171740 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_cHotboxPtr_dtor, func_00135C90)
static inline void merge_flush_func_00171740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171740 */

/* merge_units: begin func_001717A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct TZEvt { char pad[0x24]; unsigned char kind; char pad2[0xB]; int arg; } TZEvt;
class TZ { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
 virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
 virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void f(int a); };
#if 0 /* merge_units */
extern "C" int* cMessage_Name(TZEvt* e);
#endif /* merge_units */
#define cMessage_Name(a0) (cMessage_Name((void *)(a0))) /* merge_units */


extern "C" int D_004EE698;
extern "C" void cHotbox_HandleEnter(TZ* self, int a);
extern "C" void cHotbox_HandleExit(TZ* self, int a);
extern "C" unsigned char cBuddyHotbox_HandleMessage(TZ* self, TZEvt* e) {
    unsigned char r;
    int t = *cMessage_Name(e);
    if (t == D_004EE698) {
        switch (e->kind) {
        case 0: cHotbox_HandleEnter(self, e->arg); break;
        case 1: break;
        case 2: cHotbox_HandleExit(self, e->arg); break;
        case 3: self->f(e->arg); break;
        }
        r = 1;
    } else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001717A0(void) {}
#undef cMessage_Name /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001717A0 */

/* merge_units: begin func_00171880 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x1C]; unsigned char kind; char pad21[0x1F]; } Msg_1880;
typedef struct { void* target; } Lnk_1880;
typedef struct { char pad[0x68]; Lnk_1880* link; char pad6c[0x28]; int x94; } Obj_1880;
void cGOBJTriggerEventMsg_ctor(Msg_1880* m, int type, int a, int b, Obj_1880* src);
int QueueMessage_cMessageR_cSystemP_int(Msg_1880*, void*, int);
#if 0 /* merge_units */
int cMessage_dtor(Msg_1880*, int);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern char D_004DAF10[];
static inline unsigned char IsLocal_1880(void) { unsigned char v; if (g_IsMultiplayer) v = D_005721C0; else v = 1; return v; }
/* send a trigger event (type 7) to the linked target when networked */
int cBuddyHotbox_HandleInteract(Obj_1880* self, int arg)
{
    if (g_IsMultiplayer) {
        Msg_1880 m;
        cGOBJTriggerEventMsg_ctor(&m, 7, self->x94, arg, self);
        m.kind = IsLocal_1880() ? 1 : 2;
        QueueMessage_cMessageR_cSystemP_int(&m, self->link->target, 0);
        m.vt = D_004DAF10;
        cMessage_dtor(&m, 0);
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171880(void) {}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171880 */

/* merge_units: begin func_00171920 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cGOBJTriggerEventMsg_dtor, D_004DAF10, cMessage_dtor)
static inline void merge_flush_func_00171920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171920 */

/* merge_units: begin func_00171980 */
#pragma push /* merge_units */
/* trigger-zone class table (handler cBuddyHotbox_HandleMessage) */
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_NextFrame();
extern void cGOBJ_CriticalNextFrame();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cHotbox_Intersects();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
#if 0 /* merge_units */
extern void cBuddyHotbox_HandleMessage();
#endif /* merge_units */

extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cGOBJ_GetFloorPlane();
extern void func_00140E90();
extern void cGOBJ_GetHealthState();
extern void cGOBJ_IsGeneratorCreated();
extern void cGOBJ_GetTargetPosition();
extern void cGOBJ_GetLosPosition();
extern void cGOBJ_HasHeadset();
extern void cGOBJ_SetStatus();
extern void cGOBJ_GetStatus();
extern void cGOBJ_GetChildList_void();
extern void cGOBJ_GetChildList_void_2();
extern void cGOBJ_ScaleBBox();
extern void cGOBJ_GetTargetPriority();
extern void cGOBJ_GetMovementState();
extern void cGOBJ_GetSubTargetAimAdjust();
extern void cGOBJ_GetNumSubTargets();
extern void cGOBJ_IsAimed();
extern void cGOBJ_InitNetwork();
extern void cGOBJ_CheckBullet();
extern void cHotbox_Disable();
extern void cHotbox_Enable();
extern void cHotbox_getSOBJClassId();
extern void cHotbox_ScriptHandleMessage();
#if 0 /* merge_units */
extern void cBuddyHotbox_HandleInteract();
#endif /* merge_units */

extern void cHotbox_Render();
extern void cHotbox_IsDeliverable();
extern void cBuddyHotbox_dtor();
extern void cHotbox_Init();
extern void cHotbox_Load();
extern void cHotbox_GetBBox();
extern void cHotbox_NetEnable();
extern void cHotbox_NetDisable();
extern void cHotbox_NetActivate();
extern void cHotbox_NetDeactivate();
extern void cHotbox_IsNetworked();
extern void cGOBJ_GetTransform_ForFloorTravel();
extern void cGOBJ_GetCameraCollisionReferencePoint();
extern void cGOBJ_GetTransform_ForCameraTracking();
extern void cGOBJ_GetTransform_ForTeleporting();
extern void cGOBJ_GetCenterOfMass();
extern void cGOBJ_GetActivationPoint();
extern void cGOBJ_v35();
extern void cGOBJ_GetMatrix();
extern void cGOBJ_SetTranslation_ResetPhysics();
extern void cGOBJ_SetRotation_ResetPhysics();
extern void cGOBJ_SetTransform_ResetPhysics();
extern void cGOBJ_ApplyTranslation();
extern void cGOBJ_ApplyLocalRotation();
extern void cGOBJ_ApplyTransform();
extern void cGOBJ_SetTranslation();
extern void cGOBJ_SetRotation();
extern void cGOBJ_SetTransform();
extern void cGOBJ_Deactivate();
extern void cGOBJ_ProcessMessage();
void * const D_004D99A0[72] = { (void*)0x0, (void*)0x0, (void*)cBuddyHotbox_dtor, (void*)cBuddyHotbox_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cHotbox_IsNetworked, (void*)cSystem_SendCreated, (void*)cHotbox_NetActivate, (void*)cHotbox_NetDeactivate, (void*)cHotbox_NetEnable, (void*)cHotbox_NetDisable, (void*)cHotbox_IsDeliverable, (void*)cHotbox_getSOBJClassId, (void*)cHotbox_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cHotbox_Init, (void*)cHotbox_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cHotbox_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cHotbox_Enable, (void*)cHotbox_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cHotbox_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cHotbox_Intersects, (void*)cBuddyHotbox_HandleInteract, (void*)0x0, (void*)0x0 };
extern void cHotbox_ctor_cPopulationR_int(cHotbox* self, int a1, int a2);

/* Trigger-zone constructor: a cHotbox with its own class table. */
cHotbox* cBuddyHotbox_ctor(cHotbox* self, int a1) {
    cHotbox_ctor_cPopulationR_int(self, a1, 12);
    self->vtable = ((char*)D_004D99A0);
    return self;
}
static inline void merge_flush_func_00171980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171980 */
