#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void func_00464880();
extern "C" void func_00464890();
extern "C" void func_004648C0();
extern "C" void func_00464A90();
extern "C" void func_00464B00();
extern "C" void func_00464B30();
extern "C" void func_00464B70();
extern void * const D_004E18C0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00464820(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E18C0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E18C0[24] = { (void*)0x0, (void*)0x0, (void*)func_00464820, (void*)func_00464B70, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00464B30, (void*)func_00464B00, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_004648C0, (void*)func_00464A90, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00464880, (void*)func_00464890, (void*)0x0 };
