/*
 * Libs/SFOLib/Source/gameobj: 3 files, 00392B50-00392C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00392B50 */
#pragma push /* merge_units */
#include "types.h"
/* cSKM_GOBJ_Load */
typedef struct { void* skel; int p50; int pad[2]; float a, b, c, d, e; } Pt2_MCInit;
typedef struct { char pad0[0x50]; int x50; char pad54[0xC]; char app[0x70]; char xD0[0x2B94]; void* p2C64; char pad2C68[0x1E8]; char ctx[0x10]; } Pt2_SkelActor;
extern char D_0053BB70[];
extern void cMan_Load(void*, int, int, int);
extern void* cSkeletonDataBank_GetSkeletonData(void*, void*);
extern void cSkeleton_Reset(void*, Pt2_MCInit*);
extern void cMan_SetBoneSet(void*, int);

void cSKM_GOBJ_Load(Pt2_SkelActor* a, int* desc) {
    Pt2_MCInit init;
    void* s;
    cMan_Load(a->app, desc[0], desc[1], desc[2]);
    a->p2C64 = a->ctx;
    s = cSkeletonDataBank_GetSkeletonData(D_0053BB70, a->xD0);
    {
        int p = a->x50;
        float c = 0.2f;
        float o = 1.0f;
        float h = 0.5f;
        init.skel = s;
        init.p50 = p;
        init.a = o;
        init.b = h;
        init.c = c;
        init.d = c;
        init.e = c;
    }
    cSkeleton_Reset(a->ctx, &init);
    cMan_SetBoneSet(a->app, -1);
}
static inline void merge_flush_func_00392B50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392B50 */

/* merge_units: begin func_00392BF0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#pragma exceptions off

struct VObj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21();
    virtual void Method90(int a, int b); /* +0x90 */
};

/* Calls the object's virtual method at vtable +0x90 with (a, 0). */
extern "C" void cSKM_GOBJ_Init(VObj* obj, int a)
{
    obj->Method90(a, 0);
}
static inline void merge_flush_func_00392BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392BF0 */

/* merge_units: begin func_00392C10 */
#pragma push /* merge_units */
typedef struct { char pad[0x2EC0]; } F8Actor_pad;
typedef struct {
    void* vt;
    char pad4[0x5C];
    char x60[0x2E50 - 0x60];
    char x2E50[4];
    char x2E54[0x14];
    char x2E68[0x2EC0 - 0x2E68];
    char x2EC0[0x10];
    char x2ED0[0xF0];
    char x2FC0[4];
} F8Actor_392;
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_CriticalNextFrame();
extern void cGOBJ_CriticalUpdateMotion();
extern void cSKM_GOBJ_UpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cSKM_GOBJ_Load();
extern void cGOBJ_getSOBJClassId();
extern void cGOBJ_ScriptHandleMessage();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSKM_GOBJ_GetCenterOfMass();
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
extern void cGOBJ_IsNetworked();
extern void cGOBJ_CheckBullet();
extern void cSKM_GOBJ_GetBBox();
extern void cSKM_GOBJ_GetFloorPoly();
extern void cSKM_GOBJ_NetDeactivate();
extern void cSKM_GOBJ_Deactivate();
extern void cSKM_GOBJ_NetActivate();
extern void cSKM_GOBJ_Activate();
extern void cSKM_GOBJ_Render();
extern void cSKM_GOBJ_NextFrame();
extern void cSKM_GOBJ_Init();
extern void cGOBJ_GetTransform_ForFloorTravel();
extern void cGOBJ_GetCameraCollisionReferencePoint();
extern void cGOBJ_GetTransform_ForCameraTracking();
extern void cGOBJ_GetTransform_ForTeleporting();
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
extern void cGOBJ_ProcessMessage();
extern void cGOBJ_HandleMessage();
extern void * const D_004DF740[];
extern void cSkaSystem_DetachParent(void* p);
extern void cSkaSystem_DetachChildren(void* p);
extern void cTreeNode_cSkaSystemPtr_dtor(void* p, int f);
extern void cSkaParams_dtor(void* p, int f);
extern void std_vector_deleter_cSkaPlaybackItem_dtor(void* p, int f);
extern void std_vector_deleter_cBone_dtor(void* p, int f);
extern void cMan_dtor(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void F8L3a(void* p) { if (p) std_vector_deleter_cSkaPlaybackItem_dtor(p, 0); }
static inline void F8L2a(void* p) { if (p) F8L3a(p); }
static inline void F8L1a(void* p) { if (p) F8L2a(p); }
static inline void F8L3b(void* p) { if (p) std_vector_deleter_cBone_dtor(p, 0); }
static inline void F8L2b(void* p) { if (p) F8L3b(p); }
static inline void F8L1b(void* p) { if (p) F8L2b(p); }
F8Actor_392* cSKM_GOBJ_dtor(F8Actor_392* a, short del)
{
    if (a) {
        a->vt = ((char*)D_004DF740);
        if (a->x2EC0) {
            cSkaSystem_DetachParent(a->x2EC0);
            cSkaSystem_DetachChildren(a->x2EC0);
            cTreeNode_cSkaSystemPtr_dtor(a->x2FC0, -1);
            cSkaParams_dtor(a->x2ED0, -1);
        }
        if (a->x2E50) {
            F8L1a(a->x2E68);
            F8L1b(a->x2E54);
        }
        cMan_dtor(a->x60, -1);
        cGOBJ_dtor(a, 0);
        if (del > 0)
            operator_delete(a);
    }
    return a;
}
void * const D_004DF740[72] = { (void*)0x0, (void*)0x0, (void*)cSKM_GOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cSKM_GOBJ_NetActivate, (void*)cSKM_GOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cSKM_GOBJ_Init, (void*)cSKM_GOBJ_Load, (void*)cSKM_GOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cSKM_GOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cSKM_GOBJ_Render, (void*)cSKM_GOBJ_Activate, (void*)cSKM_GOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cSKM_GOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cSKM_GOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)cSKM_GOBJ_GetFloorPoly, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00392C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392C10 */
