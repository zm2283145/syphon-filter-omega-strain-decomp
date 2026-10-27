/*
 * SFOGame/Source/hotbox: 2 files, 00171920-00171980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

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
extern void cBuddyHotbox_HandleMessage();
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
extern void cBuddyHotbox_HandleInteract();
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
