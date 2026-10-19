#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_00293890();
extern "C" void GuiMissionSetup_GetClassName();
extern "C" void GuiMissionSetup_IsType();
extern "C" void GuiMissionSetup_HandleEvent();
extern "C" void GuiMissionSetup_HandleInput();
extern "C" void GuiMissionSetup_Deactivate();
extern "C" void GuiMissionSetup_Activate();
extern "C" void GuiScreen_PollLobby();
extern "C" void GuiScreen_Update();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiScreen_Wake();
extern "C" void GuiScreen_Init();
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
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const GuiMissionSetup_vtable[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O002A0CF0 { void* vtable; char pad[0x84]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O002A0CF0* GuiMissionSetup_dtor(O002A0CF0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)GuiMissionSetup_vtable);
        func_0044F970(self->m2, -1);
        func_0044F970(self->m1, -1);
        func_0044F970(self->m0, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiMissionSetup_vtable[28] = { (void*)0x0, (void*)0x0, (void*)GuiMissionSetup_dtor, (void*)GuiScreen_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiScreen_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiMissionSetup_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiScreen_Update, (void*)GuiMissionSetup_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMissionSetup_GetClassName, (void*)GuiMissionSetup_IsType, (void*)func_00293890, (void*)GuiScreen_PollLobby, (void*)GuiMissionSetup_Activate, (void*)GuiMissionSetup_Deactivate, (void*)0x0 };
