#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWeaponStats_IsType();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void func_004235C0();
extern "C" void func_004235E0();
extern "C" void func_00423610();
extern "C" void func_00423660();
extern "C" void func_00423670();
extern "C" void GuiArrayWidget_OnLoseFocus();
extern "C" void GuiArrayWidget_OnGainFocus();
extern "C" void func_00426100();
extern "C" void func_004261D0();
extern "C" void func_00426350();
extern "C" void func_004557C0();
extern "C" void func_00455AE0();
extern "C" void func_00455B60();
extern "C" void func_004572E0();
extern void * const D_004E1350[];
void* func_00426940(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00457280(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1350);
        func_00426940(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1350[32] = { (void*)0x0, (void*)0x0, (void*)func_00457280, (void*)func_00455B60, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_004261D0, (void*)func_00426100, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)func_004557C0, (void*)func_00423670, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_004572E0, (void*)GuiWeaponStats_IsType, (void*)func_00426350, (void*)func_00423660, (void*)func_00423610, (void*)func_00455AE0, (void*)func_004235E0, (void*)func_004235C0, (void*)0x0, (void*)0x0, (void*)0x0 };
