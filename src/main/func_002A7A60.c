#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_002A7AC0();
extern "C" void func_002A7AD0();
extern "C" void GuiMessageBox_HandleInput();
extern "C" void func_002A7C20();
extern "C" void GuiMessageBox_Init();
extern "C" void GuiMessageBox_Sleep();
extern "C" void GuiMessageBox_Wake();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041E470();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DD9D0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_002A7A60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD9D0);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD9D0[24] = { (void*)0x0, (void*)0x0, (void*)func_002A7A60, (void*)GuiMessageBox_Init, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiMessageBox_Wake, (void*)GuiMessageBox_Sleep, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiMessageBox_HandleInput, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_002A7C20, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002A7AC0, (void*)func_002A7AD0, (void*)0x0 };
