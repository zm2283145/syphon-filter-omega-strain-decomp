#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiCommandCenter_GetClassName();
extern "C" void func_00294220();
extern "C" void GuiCommandCenter_First();
extern "C" void GuiCommandCenter_Leave();
extern "C" void GuiCommandCenter_HandleInput();
extern "C" void GuiCommandCenter_HandleEvent();
extern "C" void GuiCommandCenter_Update();
extern "C" void GuiCommandCenter_Deactivate();
extern "C" void GuiCommandCenter_Activate();
extern "C" void GuiCommandCenter_Wake();
extern "C" void GuiCommandCenter_Init();
extern "C" void func_0033CCA0();
extern "C" void GuiScreen_Sleep();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DD4F0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_00138350(void* self, short deleteFlag);
void func_0033D430(void* self, int flags);
void operator_delete(void* p);
}
struct O294190 { void* vtable; char pad[0x200]; char items[0x11][0xC]; };
extern "C" O294190* GuiCommandCenter_dtor(O294190* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD4F0);
        __destroy_array(self->items, (void*)func_00138350, 0xC, 0x11);
        func_0033D430(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DD4F0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCommandCenter_dtor, (void*)GuiCommandCenter_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiCommandCenter_Wake, (void*)GuiScreen_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiCommandCenter_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiCommandCenter_Update, (void*)GuiCommandCenter_HandleEvent, (void*)func_0041F210, (void*)GuiCommandCenter_First, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiCommandCenter_GetClassName, (void*)func_00294220, (void*)GuiCommandCenter_Leave, (void*)func_0033CCA0, (void*)GuiCommandCenter_Activate, (void*)GuiCommandCenter_Deactivate, (void*)0x0 };
