/*
 * SFOGame/Source/GameGOBJ: 1 file, 0021AC80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021AC80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
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
extern "C" void cGameGOBJ_Render();
extern "C" void cGameGOBJ_CriticalNextFrame();
extern "C" void cGameGOBJ_NextFrame();
extern "C" void cGameGOBJ_HandleMessage();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void cGameGOBJ_NetDeactivate();
extern "C" void cGameGOBJ_NetActivate();
extern "C" void cGameGOBJ_Deactivate();
extern "C" void cGameGOBJ_Activate();
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
void operator_delete(void* p);
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
static inline void merge_flush_func_0021AC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AC80 */
