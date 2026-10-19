#pragma cplusplus on

#include "types.h"

/* Deleting destructor: subobject at +0x88 with strings at +0xC4/+0xB8, base func_0033D430. */
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
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void func_0017ECD0();
extern "C" void func_0017F080();
extern "C" void func_00180020();
extern "C" void func_00180780();
extern "C" void func_00180790();
extern "C" void func_001807A0();
extern "C" void func_001AEFE0();
extern "C" void AnimChannel_AddOffset();
extern "C" void AnimChannel_DirectValueZero();
extern "C" void func_00293890();
extern "C" void func_0029CB90();
extern "C" void func_0029CBA0();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
extern "C" void func_003604E0();
extern "C" void GuiAgentInfo_Update();
extern "C" void GuiAgentInfo_HandleEvent();
extern "C" void GuiAgentInfo_HandleInput();
extern "C" void GuiAgentInfo_Deinit();
extern "C" void GuiAgentInfo_Init();
extern "C" void GObj_GetWorldMatrix();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void func_003CD4A0();
extern "C" void Node_GetWorldMatrix();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CE9D0();
extern "C" void func_003CEA00();
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
extern "C" void func_0041F210();
extern void * const D_004DF350[];
void operator_delete(void* allocation);
void* String_Dtor(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
}
struct O360430 { void* vtable; };
extern "C" O360430* func_00360430(O360430* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF350);
        char* p = (char*)self + 0x88;
        if (p) {
            char* a = (char*)self + 0xC4;
            if (a)
                String_Dtor(a, 0);
            char* b = (char*)self + 0xB8;
            if (b)
                String_Dtor(b, 0);
        }
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF350[120] = { (void*)0x0, (void*)0x0, (void*)func_00360430, (void*)GuiAgentInfo_Init, (void*)GuiAgentInfo_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiAgentInfo_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiAgentInfo_Update, (void*)GuiAgentInfo_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAgentInfo_GetClassName, (void*)func_003604E0, (void*)func_00293890, (void*)GuiScreen_PollLobby, (void*)func_0029CB90, (void*)func_0029CBA0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)func_0017F080, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_00180780, (void*)func_00180790, (void*)func_001807A0, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)func_00180020, (void*)0x0, (void*)0x0, (void*)Curve_Retarget, (void*)Curve_VirtualNop, (void*)Curve_SetVelocity, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)func_001AEFE0, (void*)AnimChannel_AddOffset, (void*)AnimChannel_DirectValueZero, (void*)AnimChannel_DirectDerivedZero, (void*)AnimChannel_PreUpdate, (void*)AnimChannel_ClampValue, (void*)AnimChannel_UpdateRate, (void*)0x0, (void*)0x0, (void*)0x0 };
