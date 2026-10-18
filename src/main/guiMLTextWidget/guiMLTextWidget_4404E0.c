#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293950();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_BaseWake();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void func_00440540();
extern "C" void func_00440550();
extern "C" void GuiWeaponDisplay_Draw();
extern "C" void GuiWeaponDisplay_Update();
extern "C" void GuiWeaponDisplay_Init();
extern void * const D_004E11A0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_004404E0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E11A0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E11A0[24] = { (void*)0x0, (void*)0x0, (void*)func_004404E0, (void*)GuiWeaponDisplay_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_00293950, (void*)GuiWeaponDisplay_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWeaponDisplay_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00440540, (void*)func_00440550, (void*)0x0 };
