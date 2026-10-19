#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiOnlineConnect_GetClassName();
extern "C" void func_00293890();
extern "C" void GuiOnlineConnect_IsType();
extern "C" void func_0029CB90();
extern "C" void func_0029CBA0();
extern "C" void GuiOnlineConnect_Update();
extern "C" void GuiOnlineConnect_HandleEvent();
extern "C" void GuiOnlineConnect_HandleInput();
extern "C" void GuiOnlineConnect_Sleep();
extern "C" void GuiOnlineConnect_Wake();
extern "C" void GuiOnlineConnect_Deinit();
extern "C" void GuiOnlineConnect_Init();
extern "C" void GuiScreen_PollLobby();
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
extern void * const GuiOnlineConnect_vtable[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O0029CAC0 { void* vtable; char pad[0x94]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O0029CAC0* GuiOnlineConnect_dtor(O0029CAC0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)GuiOnlineConnect_vtable);
        func_0044F970(self->m2, -1);
        func_0044F970(self->m1, -1);
        func_0044F970(self->m0, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const GuiOnlineConnect_vtable[28] = { (void*)0x0, (void*)0x0, (void*)GuiOnlineConnect_dtor, (void*)GuiOnlineConnect_Init, (void*)GuiOnlineConnect_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiOnlineConnect_Wake, (void*)GuiOnlineConnect_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiOnlineConnect_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiOnlineConnect_Update, (void*)GuiOnlineConnect_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiOnlineConnect_GetClassName, (void*)GuiOnlineConnect_IsType, (void*)func_00293890, (void*)GuiScreen_PollLobby, (void*)func_0029CB90, (void*)func_0029CBA0, (void*)0x0 };
