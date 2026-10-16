#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293950();
extern "C" void GuiCharacterDisplay_GetClassName();
extern "C" void GuiCharacterDisplay_IsType();
extern "C" void GuiCharacterDisplay_Draw();
extern "C" void func_00326850();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void func_0041EBF0();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern void * const D_004DE670[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00326770(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE670);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE670[24] = { (void*)0x0, (void*)0x0, (void*)func_00326770, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00326850, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)GuiCharacterDisplay_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiCharacterDisplay_GetClassName, (void*)GuiCharacterDisplay_IsType, (void*)0x0 };
