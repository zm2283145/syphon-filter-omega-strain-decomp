#pragma cplusplus on

#include "types.h"

/* Deleting destructor: subobject at +0x88 with strings at +0xC4/+0xB8, base GuiScreen_dtor. */
extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void AnimChannel_ClampValue();
extern "C" void AnimChannel_DirectDerivedZero();
extern "C" void AnimChannel_PreUpdate();
extern "C" void AnimChannel_UpdateRate();
extern "C" void Controller_DeathNotice();
extern "C" void Curve_Retarget();
extern "C" void Curve_SetVelocity();
extern "C" void Curve_VirtualNop();
extern "C" void GuiAgentInfo_GetClassName();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGOBJ_v0B();
extern "C" void cGOBJ_v0C();
extern "C" void GObj_GetID();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void Object_GetEye();
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
extern "C" void AnimChannel_AddOffset();
extern "C" void AnimChannel_DirectValueZero();
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiLobbyScreen_StartLobbyScreen();
extern "C" void GuiLobbyScreen_ExitLobbyScreen();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
extern "C" void GuiAgentInfo_IsType();
extern "C" void GuiAgentInfo_Update();
extern "C" void GuiAgentInfo_HandleEvent();
extern "C" void GuiAgentInfo_HandleInput();
extern "C" void GuiAgentInfo_Deinit();
extern "C" void GuiAgentInfo_Init();
extern "C" void GObj_GetWorldMatrix();
extern "C" void cNode_v3A();
extern "C" void cGOBJ_v39();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void cGOBJ_v35();
extern "C" void Node_GetWorldMatrix();
extern "C" void cNode_v2B();
extern "C" void cNode_v2A();
extern "C" void cNode_v29();
extern "C" void cNode_v28();
extern "C" void cNode_v27();
extern "C" void cNode_v26();
extern "C" void cNode_v25();
extern "C" void cNode_v24();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void cNode_v07();
extern "C" void cNode_v06();
extern "C" void cNode_v14();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Load();
extern void * const GuiAgentInfo_vtable[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* GuiScreen_dtor(void* self, short deleteFlag);
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
        GuiScreen_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiAgentInfo_vtable[120] = { (void*)0x0, (void*)0x0, (void*)GuiAgentInfo_dtor, (void*)GuiAgentInfo_Init, (void*)GuiAgentInfo_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiAgentInfo_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiAgentInfo_Update, (void*)GuiAgentInfo_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAgentInfo_GetClassName, (void*)GuiAgentInfo_IsType, (void*)GuiSaveAgentWidget_SaveDone, (void*)GuiScreen_PollLobby, (void*)GuiLobbyScreen_StartLobbyScreen, (void*)GuiLobbyScreen_ExitLobbyScreen, (void*)0x0, (void*)0x0, (void*)0x0, (void*)cCAMERA_GOBJ_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cNode_v06, (void*)cNode_v07, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)cCAMERA_GOBJ_Init, (void*)cCAMERA_GOBJ_Load, (void*)cCAMERA_GOBJ_NextFrame, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)Object_GetEye, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)Actor_ApplyContactDamage, (void*)cGOBJ_CheckBullet, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)cSplinedMotion_float_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)Curve_Retarget, (void*)Curve_VirtualNop, (void*)Curve_SetVelocity, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_Scalar0To1_dtor, (void*)AnimChannel_AddOffset, (void*)AnimChannel_DirectValueZero, (void*)AnimChannel_DirectDerivedZero, (void*)AnimChannel_PreUpdate, (void*)AnimChannel_ClampValue, (void*)AnimChannel_UpdateRate, (void*)0x0, (void*)0x0, (void*)0x0 };
