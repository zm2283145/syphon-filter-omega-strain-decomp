#pragma cplusplus on

#include "types.h"

/* Deleting destructor: subobject at +0x88 with strings at +0xC4/+0xB8, base GuiLobbyScreen_dtor. */
extern "C" {
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation();
extern "C" void cSplinedMotion_Scalar0To1_ZeroVel();
extern "C" void cSplinedMotion_Scalar0To1_UpdateSplinePoints();
extern "C" void cSplinedMotion_Scalar0To1_UpdateVelocity();
extern "C" void cGOBJ_Die();
extern "C" void cSplinedMotion_float_UpdateSplinePoints();
extern "C" void cSplinedMotion_float_UpdateVelocity();
extern "C" void cSplinedMotion_float_FixUpResultOfSplineEvaluation();
extern "C" void GuiAgentInfo_GetClassName();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
extern "C" void cGOBJ_Activate();
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
extern "C" void func_0017ECD0();
extern "C" void cCAMERA_GOBJ_dtor();
extern "C" void cSplinedMotion_float_TeleportByDelta();
extern "C" void cCAMERA_GOBJ_Init();
extern "C" void cCAMERA_GOBJ_Load();
extern "C" void cCAMERA_GOBJ_NextFrame();
extern "C" void cSplinedMotion_Scalar0To1_dtor();
extern "C" void cSplinedMotion_Scalar0To1_TeleportByDelta();
extern "C" void cSplinedMotion_Scalar0To1_InitPos();
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiLobbyScreen_StartLobbyScreen();
extern "C" void GuiLobbyScreen_ExitLobbyScreen();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
extern "C" void GuiAgentInfo_IsClass();
extern "C" void GuiAgentInfo_Update();
extern "C" void GuiAgentInfo_onMessage();
extern "C" void GuiAgentInfo_onInput();
extern "C" void GuiMissionLobbyScreen_onRemove();
extern "C" void GuiAgentInfo_onAdd();
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
extern "C" void cGOBJ_Deactivate();
extern "C" void cGOBJ_NetDeactivate();
extern "C" void cGOBJ_NetActivate();
extern "C" void cGOBJ_Render();
extern "C" void cGOBJ_ProcessMessage();
extern "C" void cGOBJ_HandleMessage();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_Load();
extern void * const GuiAgentInfo_vtable[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* GuiLobbyScreen_dtor(void* self, short deleteFlag);
}
struct O360430 { void* vtable; };
extern "C" O360430* GuiAgentInfo_dtor(O360430* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)GuiAgentInfo_vtable);
        char* p = (char*)self + 0x88;
        if (p) {
            char* a = (char*)self + 0xC4;
            if (a)
                String_Dtor(a, 0);
            char* b = (char*)self + 0xB8;
            if (b)
                String_Dtor(b, 0);
        }
        GuiLobbyScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiAgentInfo_vtable[120] = { (void*)0x0, (void*)0x0, (void*)GuiAgentInfo_dtor, (void*)GuiAgentInfo_onAdd, (void*)GuiMissionLobbyScreen_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiAgentInfo_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiAgentInfo_Update, (void*)GuiAgentInfo_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAgentInfo_GetClassName, (void*)GuiAgentInfo_IsClass, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiLobbyScreen_StartLobbyScreen, (void*)GuiLobbyScreen_ExitLobbyScreen, (void*)0x0, (void*)0x0, (void*)0x0, (void*)cCAMERA_GOBJ_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_getSOBJClassId, (void*)cGOBJ_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cCAMERA_GOBJ_Init, (void*)cCAMERA_GOBJ_Load, (void*)cCAMERA_GOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die, (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)cSplinedMotion_float_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_float_UpdateSplinePoints, (void*)cSplinedMotion_float_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_float_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_Scalar0To1_dtor, (void*)cSplinedMotion_Scalar0To1_TeleportByDelta, (void*)cSplinedMotion_Scalar0To1_InitPos, (void*)cSplinedMotion_Scalar0To1_ZeroVel, (void*)cSplinedMotion_Scalar0To1_UpdateSplinePoints, (void*)cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_Scalar0To1_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
