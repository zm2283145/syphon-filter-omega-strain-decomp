/*
 * SFOGame/Source/backpack: 5 files, 00257450-00257620
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00257450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(int, int);

int std_vector_cBackpackPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cBackpackPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00257450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257450 */

/* merge_units: begin func_00257480 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}

struct Backpack {
    char pad0[0xC];
    int id;              /* 0x0C */
    int netid;           /* 0x10 */
    unsigned char active; /* 0x14 */
};

extern "C" {
extern int g_BackpackList;
extern char D_004A7B50[];
void* cMemMan_Allocate(int heap, int size, char* file, int line);
Backpack* cBackpack_ctor(void* p, int rec);
#if 0 /* merge_units */
void std_vector_cBackpackPtr_push_back(int list, Backpack** bp);
#endif /* merge_units */
int std_vector_cBackpackPtr_push_back(PtrVec* v, int value); /* merge_units */
#define std_vector_cBackpackPtr_push_back(a0, a1) ((void)std_vector_cBackpackPtr_push_back((PtrVec *)(a0), (int)(a1))) /* merge_units */

void cNetObj_AddSystem(int a, int b, void* c);
}

static inline void* New_00257480(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004A7B50, line);
}

extern "C" Backpack* cBackpack_NewBackpack_cPopulationR(int rec)
{
    Backpack* bp;
    void* p = New_00257480(0x318, 0x16F);
    if (p) p = cBackpack_ctor(p, rec);
    bp = (Backpack*)p;
    std_vector_cBackpackPtr_push_back(g_BackpackList, &bp);
    if (g_IsMultiplayer) {
        Backpack* b = bp;
        b->netid = b->id;
        if (!(g_IsMultiplayer ? D_005721C0 : 1)) b->active = 0;
        int nid = b->netid;
        cNetObj_AddSystem(nid, NetObjId(), b);
    }
    return bp;
}
#undef std_vector_cBackpackPtr_push_back /* merge_units */
static inline void merge_flush_func_00257480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257480 */

/* merge_units: begin func_00257620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector helper.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value) */
int std_vector_cBackpackPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00257620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257620 */

/* merge_units: begin func_00257640 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "vu0_ops.h"
extern "C" {
extern int D_00494178;
extern int D_005721A8;
#if 0 /* merge_units */
extern bool D_005721C0;
#endif /* merge_units */
#define D_005721C0 (*(bool*)&D_005721C0) /* merge_units */

#if 0 /* merge_units */
extern bool g_IsMultiplayer;
#endif /* merge_units */
#define g_IsMultiplayer (*(bool*)&g_IsMultiplayer) /* merge_units */

int NetGetMyClientIndex(int*,int);
int NetGetPeerToPeerHostClientIndex(int,int*);
}
#pragma push
#pragma inline_depth(12)
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r=0;int a=D_005721A8;if(g_IsMultiplayer) { if(D_00494178==-1)NetGetMyClientIndex(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline int KnownLocal(bool online) { int r=0;int a=D_005721A8;if(online) { if(D_00494178==-1)NetGetMyClientIndex(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline bool Hosting() {bool r;if(g_IsMultiplayer)r=D_005721C0;else {r=1; /* Preserve the offline branch. */ asm { .set reorder }}return r;}
static inline int OwnerId() {int id;if(Hosting())id=LocalId();else{int tmp;NetGetPeerToPeerHostClientIndex(D_005721A8,&tmp);id=tmp;}return id;}
struct Mat { __int128 q[4]; Mat() {} };
struct Backpack_00257640 {
 VPAD32(a) VPAD2(b) virtual void attach(void*,int);
 char pad4[8];int id,netid;unsigned char active;char pad15[0x1A];unsigned char flag2f;char pad30[0x30];unsigned char flag60;char pad61[0x28F];unsigned char dropped;char pad2f1[0xF];int x300,x304,owner,x30c;float timer;int x314;
};
extern "C" {
extern float D_004F7F70;
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
extern "C" void cGOBJ_Activate();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cBackpack_dtor();
extern "C" void cBackpack_HandleMessage();
extern "C" void cBackpack_getSOBJClassId();
extern "C" void cBackpack_ScriptHandleMessage();
extern "C" void cBackpack_v10();
extern "C" void cBackpack_Render();
extern "C" void cBackpack_GetBBox();
extern "C" void cBackpack_ApplyTranslation();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
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
extern "C" void cGOBJ_ApplyLocalRotation();
extern "C" void cGOBJ_ApplyTransform();
extern "C" void cGOBJ_SetTranslation();
extern "C" void cGOBJ_SetRotation();
extern "C" void cGOBJ_SetTransform();
extern "C" void cGOBJ_Deactivate();
extern "C" void cGOBJ_NetDeactivate();
extern "C" void cGOBJ_NetActivate();
extern "C" void cGOBJ_Load();
extern "C" void cGOBJ_Init();
extern "C" void cGOBJ_ProcessMessage();
void * const D_004DC350[68] = { (void*)0x0, (void*)0x0, (void*)cBackpack_dtor, (void*)cBackpack_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cBackpack_getSOBJClassId, (void*)cBackpack_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cGOBJ_Init, (void*)cGOBJ_Load, (void*)cBackpack_v10, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cBackpack_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cBackpack_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cBackpack_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
extern char g_IdentityMatrix[];
#if 0 /* merge_units */
void* cMemMan_Allocate(int,int,char*,int);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

void cBackpack_GarbageCollect();
void nGobjManager_GetNextId(int*,int);
void cGOBJ_ctor(void*,int*,int,int*);
void cBackpack_Clear(Backpack_00257640*,int);
#if 0 /* merge_units */
void std_vector_cBackpackPtr_push_back(int,Backpack_00257640**);
#endif /* merge_units */
#define std_vector_cBackpackPtr_push_back(a0, a1) ((void)std_vector_cBackpackPtr_push_back((PtrVec *)(a0), (int)(a1))) /* merge_units */


Mat cHuman_FigurePickupLoc(void*);
void cBackpack_SetBodyLoc(Backpack_00257640*,Mat*,int);
void cBackpack_SetBody(Backpack_00257640*,void*);
#if 0 /* merge_units */
void cNetObj_AddSystem(int,int,Backpack_00257640*);
#endif /* merge_units */
#define cNetObj_AddSystem(a0, a1, a2) (cNetObj_AddSystem((a0), (a1), (void *)(a2))) /* merge_units */

}
static inline void* AllocBack() { AllocGuard g;return cMemMan_Allocate(0,0x318,D_004A7B50,0x157); }
static inline void ConstructBack(Backpack_00257640* obj,int* id) {
 int localId; int z=0;
 if(id) { /* Keep the selected-id branch and its delay slot. */ asm { .set reorder } } else {
  int tmp;
  nGobjManager_GetNextId(&tmp,0xF5);
  tmp|=(LocalId()+1)<<24;
  localId=tmp;id=&localId;
 }
 cGOBJ_ctor(obj,id,3,&z);
 *(void**)obj=((char*)D_004DC350);
 obj->x304=-2;obj->x300=0;obj->flag2f=1;
 cBackpack_Clear(obj,0);
 obj->attach(g_IdentityMatrix,0);
 obj->dropped=1;obj->flag60=0;obj->timer=D_004F7F70;
}

static inline void Bind(Backpack_00257640* obj) {
 obj->netid=obj->id;
 if(!Hosting()) obj->active=0;
 int id=obj->netid;
 int owner=OwnerId();cNetObj_AddSystem(id,owner,obj);
}
extern "C" Backpack_00257640* cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(void* actor,int carry,int* id) {
 Backpack_00257640* result=0;
 int registry=g_BackpackList;
 cBackpack_GarbageCollect();
 Backpack_00257640* obj=(Backpack_00257640*)AllocBack();
 if(obj) ConstructBack(obj,id);
 result=obj;std_vector_cBackpackPtr_push_back(registry,&result);
 if(actor) {Mat m=cHuman_FigurePickupLoc(actor);cBackpack_SetBodyLoc(result,&m,1);}
 else {Mat m;VU0_UnitMatrix(&m);cBackpack_SetBodyLoc(result,&m,1);}
 if(carry) { /* Preserve the carry branch before clearing the owner. */ asm { .set reorder } } else actor=0;
 cBackpack_SetBody(result,actor);
 { bool online=g_IsMultiplayer;if(online) {result->owner=KnownLocal(online);Bind(result);} }
 return result;
}
#pragma pop
#undef D_005721C0 /* merge_units */
#undef g_IsMultiplayer /* merge_units */
#undef cMemMan_Allocate /* merge_units */
#undef std_vector_cBackpackPtr_push_back /* merge_units */
#undef cNetObj_AddSystem /* merge_units */
static inline void merge_flush_func_00257640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257640 */

/* merge_units: begin func_002579E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* g_HotboxTracker;
extern void cHotboxMan_RemoveHotbox(void* mgr, int effect);
extern void nGobjManager_RemoveGOBJ(int effect);
extern void cSystem_ActualScheduleDelete(int effect, float time);
/* Stop and release the attached effect. */
void cBackpack_FadeOut(Obj002579E0* obj)
{
    obj->unk314 = 0;
    if (obj->effect) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, obj->effect);
        nGobjManager_RemoveGOBJ(obj->effect);
        cSystem_ActualScheduleDelete(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
static inline void merge_flush_func_002579E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002579E0 */
