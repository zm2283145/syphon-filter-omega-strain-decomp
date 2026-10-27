/*
 * SFOGame/Source/Node: 1 file, 0015C2F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015C2F0 */
#pragma push /* merge_units */
#include "types.h"
extern void cGOBJ_ReceiveDamage();
extern void cGOBJ_NextFrame();
extern void cGOBJ_CriticalNextFrame();
extern void cGOBJ_UpdateMotion();
extern void cGOBJ_CriticalUpdateMotion();
extern void cGOBJ_Die();
extern void cGOBJ_Disable();
extern void cGOBJ_IsEnabled();
extern void cGOBJ_Enable();
extern void cGOBJ_Activate();
extern void cGOBJ_CreateXform();
extern void cGOBJ_ScriptGetRealObj();
extern void cNode_getSOBJClassId();
extern void cNode_ScriptHandleMessage();
extern void cNode_Init();
extern void cNode_Load();
extern void cNode_v34();
extern void cNode_GetTranslation();
extern void cNode_GetActivationPoint();
extern void cNode_GetCenterOfMass();
extern void cNode_v38();
extern void cNode_v39();
extern void cNode_v3B();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_SendCreated();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cGOBJ_GetFloorPlane();
extern void cGOBJ_GetBBox();
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
extern void cGOBJ_GetCameraCollisionReferencePoint();
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
extern void cGOBJ_NetDeactivate();
extern void cGOBJ_NetActivate();
extern void cGOBJ_Render();
extern void cGOBJ_ProcessMessage();
extern void cGOBJ_HandleMessage();
extern void * const cNode_vtable[];
extern void std_vector_deleter_tNodeLink_clear(void* p);
extern void std_vector_deleter_tNodeLink_dtor(void* p, int flag);
extern void cGOBJ_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_C2F0;
#pragma opt_common_subs off
S_C2F0* cNode_dtor(S_C2F0* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)cNode_vtable);
        std_vector_deleter_tNodeLink_clear((char*)self + 0x68);
        m = (char*)self + 0x68;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_tNodeLink_dtor(m, 0);
            }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma opt_common_subs reset
void * const cNode_vtable[68] = { (void*)0x0, (void*)0x0, (void*)cNode_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cNode_getSOBJClassId, (void*)cNode_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cNode_Init, (void*)cNode_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cNode_v34, (void*)cNode_GetTranslation, (void*)cNode_GetActivationPoint, (void*)cNode_GetCenterOfMass, (void*)cNode_v38, (void*)cNode_v39, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cNode_v3B, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
static inline void merge_flush_func_0015C2F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015C2F0 */
