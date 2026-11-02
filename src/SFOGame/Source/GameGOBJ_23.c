/*
 * SFOGame/Source/GameGOBJ: 12 files, 0021A7A0-0021AC80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021A7A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetCreateBlastMsg_dtor, D_004DE130, cMessage_dtor)
static inline void merge_flush_func_0021A7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A7A0 */

/* merge_units: begin func_0021A800 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern char D_004D9DE0[];

Rec0C* cSafePtr_cGOBJ_ctor_void(Rec0C* r) {
    *(int*)&r->unk4 = -2;
    r->unk0 = 0;
    return r;
}

Rec0C* cCBData_ctor(Rec0C* r, int a1, int a2, int a3) {
    r->unk8 = D_004D9DE0;
    r->unk4 = a2;
    r->unk0 = a1;
    r->unk5 = a3;
    return r;
}
static inline void merge_flush_func_0021A800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A800 */

/* merge_units: begin func_0021A840 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "linked_target_refresh.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_flag_slot16.h"
#pragma pop

#pragma cplusplus on

/* Push the value to the linked target and refresh it. */
DEFINE_LINKED_TARGET_REFRESH(cGameGOBJ_Render)
static inline void merge_flush_func_0021A840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A840 */

/* merge_units: begin func_0021A8C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Call slot 16 unless the object is active. */
DEFINE_GOBJ_FLAG_SLOT16(cGameGOBJ_CriticalNextFrame)
static inline void merge_flush_func_0021A8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A8C0 */

/* merge_units: begin func_0021A920 */
#pragma push /* merge_units */
extern void cGOBJ_NextFrame(void* self);
extern int cGOBJ_HandleMessage(void* self, int a1);

void cGameGOBJ_NextFrame(void* self) {
    cGOBJ_NextFrame(self);
}

int cGameGOBJ_HandleMessage(void* self, int a1) {
    return cGOBJ_HandleMessage(self, a1);
}
static inline void merge_flush_func_0021A920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A920 */

/* merge_units: begin func_0021A940 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vtbl; char pad04[0x18]; int size; char pad20[4]; int id; char pad28[8]; } C1Msg_21A9;
class C1Ch_21A9 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Reset(int arg);
};
typedef struct { char p0[0x10]; int target; char p14[0x2C - 0x14]; unsigned char flag; char p2d[0x78 - 0x2D]; int n; C1Ch_21A9** ch; } C1Obj_21A9;
extern "C" unsigned char g_IsMultiplayer;
extern "C" char g_cDisableMsgClass[];
extern "C" char D_004E0860[];
extern "C" void cMessage_ctor_cMessageNameR(C1Msg_21A9* m, void* type);
extern "C" void cDisableMsg_SendDisabled(C1Msg_21A9* m, int target, int x);
#if 0 /* merge_units */
extern "C" void cMessage_dtor(C1Msg_21A9* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#pragma opt_strength_reduction off
extern "C" void cGameGOBJ_Disable(C1Obj_21A9* o)
{
    int i;
    if (g_IsMultiplayer) {
        C1Msg_21A9 msg;
        cMessage_ctor_cMessageNameR(&msg, g_cDisableMsgClass);
        msg.vtbl = D_004E0860;
        msg.id = -1;
        msg.size = 0x40;
        cDisableMsg_SendDisabled(&msg, o->target, -1);
        msg.vtbl = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
    o->flag = 0;
    for (i = 0; i < o->n; i++)
        o->ch[i]->Reset(-1);
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0021A940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A940 */

/* merge_units: begin func_0021AA20 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "gobj_v07_register.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_v06_update.h"
#pragma pop

#pragma cplusplus on

class C1Ch_21A9_0021AA20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void Reset(int arg);
};
typedef struct { char p0[0x10]; int target; char p14[0x2C - 0x14]; unsigned char flag; char p2d[0x78 - 0x2D]; int n; C1Ch_21A9_0021AA20** ch; } C1Obj_21A9_0021AA20;
extern "C" char g_cEnableMsgClass[];
extern "C" char D_004E0880[];
extern "C" void cEnableMsg_SendEnabled(C1Msg_21A9* m, int target);
#if 0 /* merge_units */
extern "C" void cMessage_dtor(C1Msg_21A9* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#pragma opt_strength_reduction off
extern "C" void cGameGOBJ_Enable(C1Obj_21A9_0021AA20* o)
{
    int i;
    if (g_IsMultiplayer) {
        C1Msg_21A9 msg;
        cMessage_ctor_cMessageNameR(&msg, g_cEnableMsgClass);
        msg.vtbl = D_004E0880;
        msg.id = -1;
        msg.size = 0x40;
        cEnableMsg_SendEnabled(&msg, o->target);
        msg.vtbl = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
    o->flag = 1;
    for (i = 0; i < o->n; i++)
        o->ch[i]->Reset(-1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021AA20(void) {}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AA20 */

/* merge_units: begin func_0021AB00 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 7: notify attached object, update, register. */
DEFINE_GOBJ_V07_REGISTER(cGameGOBJ_NetDeactivate)
static inline void merge_flush_func_0021AB00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AB00 */

/* merge_units: begin func_0021AB60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 6: notify attached object, update, call slot 47. */
DEFINE_GOBJ_V06_UPDATE(cGameGOBJ_NetActivate)
static inline void merge_flush_func_0021AB60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AB60 */

/* merge_units: begin func_0021ABC0 */
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
extern "C" void cGameGOBJ_Deactivate(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    cGOBJ_Deactivate(self, arg);
    cTargetManager_RemoveGobj(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021ABC0(void) {}
#undef cTargetManager_RemoveGobj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021ABC0 */

/* merge_units: begin func_0021AC20 */
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

struct cGameGOBJ {
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

extern "C" void cGOBJ_Activate(cGameGOBJ* self, void* arg);

/* Notifies the door object (+0x64, virtual +0x5C), runs cGOBJ_Activate and virtual +0xC4. */
extern "C" void cGameGOBJ_Activate(cGameGOBJ* self, void* arg)
{
    if (self->door)
    self->door->Method5C();
    cGOBJ_Activate(self, arg);
    self->MethodC4();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021AC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021AC20 */

/* merge_units: begin func_0021AC80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_21AC80 { virtual void Destroy(int f); };
struct Obj_21AC80 { void* vt; char pad04[0x60]; VObj_21AC80* obj; char pad68[0xC]; char m74[0x10]; char m84[0x10]; };
extern "C" {
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cGameGOBJ_getSOBJClassId();
extern "C" void cGameGOBJ_ScriptHandleMessage();
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
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGameGOBJ_GetBBox();
extern "C" void cGameGOBJ_GetTargetPriority();
extern "C" void cGameGOBJ_SetParent();
#if 0 /* merge_units */
extern "C" void cGameGOBJ_Render();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_CriticalNextFrame();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_NextFrame();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_HandleMessage();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_Disable();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_Enable();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_NetDeactivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_NetActivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_Deactivate();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cGameGOBJ_Activate();
#endif /* merge_units */

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
extern void * const D_004DB4C0[];
extern char D_004A4550[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_vector_deleter_cSafePtr_cGOBJ_dtor(void* p, int f);
void std_vector_cGOBJPtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

}
static inline void L3_21AC80(void* p) { if (p) std_vector_deleter_cSafePtr_cGOBJ_dtor(p, 0); }
static inline void L2_21AC80(void* p) { if (p) L3_21AC80(p); }
static inline void L1_21AC80(void* p) { if (p) L2_21AC80(p); }
extern "C" Obj_21AC80* cGameGOBJ_dtor(Obj_21AC80* l, short flag)
{
    if (l) {
        VObj_21AC80* o;
        l->vt = ((char*)D_004DB4C0);
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            cMemMan_Deallocate(0, o, D_004A4550, 0xFE);
        }
        L1_21AC80(l->m84);
        if (l->m74)
            std_vector_cGOBJPtr_dtor(l->m74, -1);
        cGOBJ_dtor(l, 0);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}
void * const D_004DB4C0[72] = { (void*)0x0, (void*)0x0, (void*)cGameGOBJ_dtor, (void*)cGameGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGameGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGameGOBJ_NetActivate, (void*)cGameGOBJ_NetDeactivate, (void*)cGameGOBJ_NetEnable, (void*)cGameGOBJ_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameGOBJ_getSOBJClassId, (void*)cGameGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cGameGOBJ_NextFrame, (void*)cGameGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGameGOBJ_Render, (void*)cGameGOBJ_Activate, (void*)cGameGOBJ_Deactivate, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGameGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGameGOBJ_GetCollisionModel, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGameGOBJ_GetTargetPriority, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cGameGOBJ_SetParent, (void*)0x0, (void*)0x0, (void*)0x0 };
#undef operator_delete /* merge_units */
static inline void merge_flush_func_0021AC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AC80 */
