#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_0041BE50();
extern "C" void GuiTextWidget_Draw();
extern "C" void GuiTextWidget_OnSleep();
extern "C" void func_0041C560();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void GuiButtonWidget_GetClassName();
extern "C" void func_00420BB0();
extern "C" void GuiButtonWidget_OnWake();
extern "C" void GuiButtonWidget_OnEvent();
extern "C" void GuiButtonWidget_OnInput();
extern void * const D_004E0C00[];
void* func_0041C6A0(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00420B40(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0C00);
        func_0041C6A0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0C00[24] = { (void*)0x0, (void*)0x0, (void*)func_00420B40, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiButtonWidget_OnWake, (void*)GuiTextWidget_OnSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiButtonWidget_OnInput, (void*)GuiTextWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiButtonWidget_OnEvent, (void*)func_0041C560, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiButtonWidget_GetClassName, (void*)func_00420BB0, (void*)func_0041BE50 };
