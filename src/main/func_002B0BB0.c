#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_002B0C10();
extern "C" void func_002B0C20();
extern "C" void func_002B0C50();
extern "C" void func_002B0D10();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void GuiWidget_OnEvent();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern void * const D_004DDDE0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_002B0BB0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DDDE0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDDE0[24] = { (void*)0x0, (void*)0x0, (void*)func_002B0BB0, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_002B0D10, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_002B0C50, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_002B0C10, (void*)func_002B0C20, (void*)0x0 };
