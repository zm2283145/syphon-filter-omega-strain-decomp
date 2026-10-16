#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_0041BE50();
extern "C" void GuiTextWidget_Draw();
extern "C" void func_0041C310();
extern "C" void func_0041C560();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_00420BA0();
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
void * const D_004E0C00[24] = { (void*)0x0, (void*)0x0, (void*)func_00420B40, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiButtonWidget_OnWake, (void*)func_0041C310, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiButtonWidget_OnInput, (void*)GuiTextWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiButtonWidget_OnEvent, (void*)func_0041C560, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00420BA0, (void*)func_00420BB0, (void*)func_0041BE50 };
