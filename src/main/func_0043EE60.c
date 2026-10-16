#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiSliderWidget_IsType();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041EFA0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void GuiSliderWidget_ctor();
extern "C" void GuiSliderWidget_OnInput();
extern "C" void GuiSliderWidget_OnLoseFocus();
extern "C" void GuiSliderWidget_OnGainFocus();
extern "C" void GuiSliderWidget_Init();
extern void * const D_004E10C0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0043EE60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E10C0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E10C0[24] = { (void*)0x0, (void*)0x0, (void*)func_0043EE60, (void*)GuiSliderWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)GuiSliderWidget_OnGainFocus, (void*)GuiSliderWidget_OnLoseFocus, (void*)GuiSliderWidget_OnInput, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiSliderWidget_ctor, (void*)GuiSliderWidget_IsType, (void*)0x0 };
