#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWeaponStats_IsType();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern "C" void GuiArrayWidget_SendEvent21();
extern "C" void GuiArrayWidget_SendEvent20();
extern "C" void func_00423610();
extern "C" void func_00423660();
extern "C" void GuiArrayWidget_Draw();
extern "C" void GuiArrayWidget_OnLoseFocus();
extern "C" void GuiArrayWidget_OnGainFocus();
extern "C" void GuiTextArrayWidget_Sleep();
extern "C" void GuiTextArrayWidget_Wake();
extern "C" void GuiTextArrayWidget_SetDims();
extern "C" void GuiWeaponStats_HandleInput();
extern "C" void GuiWeaponStats_CellColour();
extern "C" void GuiWeaponStats_Init();
extern "C" void GuiWeaponStats_GetClassName();
extern void * const D_004E1350[];
void* GuiTextArrayWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiWeaponStats_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1350);
        GuiTextArrayWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1350[32] = { (void*)0x0, (void*)0x0, (void*)GuiWeaponStats_dtor, (void*)GuiWeaponStats_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiTextArrayWidget_Wake, (void*)GuiTextArrayWidget_Sleep, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)GuiWeaponStats_HandleInput, (void*)GuiArrayWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiWeaponStats_GetClassName, (void*)GuiWeaponStats_IsType, (void*)GuiTextArrayWidget_SetDims, (void*)func_00423660, (void*)func_00423610, (void*)GuiWeaponStats_CellColour, (void*)GuiArrayWidget_SendEvent20, (void*)GuiArrayWidget_SendEvent21, (void*)0x0, (void*)0x0, (void*)0x0 };
