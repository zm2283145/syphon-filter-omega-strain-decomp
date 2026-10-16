#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_00287DC0();
extern "C" void func_00287DD0();
extern "C" void GuiTitleScreen_HandleEvent();
extern "C" void GuiTitleScreen_Update();
extern "C" void GuiTitleScreen_HandleInput();
extern "C" void GuiTitleScreen_Wake();
extern "C" void func_002888E0();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DD0A0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00287D60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD0A0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD0A0[24] = { (void*)0x0, (void*)0x0, (void*)func_00287D60, (void*)func_002888E0, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiTitleScreen_Wake, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiTitleScreen_HandleInput, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiTitleScreen_Update, (void*)GuiTitleScreen_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00287DC0, (void*)func_00287DD0, (void*)0x0 };
