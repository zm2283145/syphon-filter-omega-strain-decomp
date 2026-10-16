#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAccountLogin_IsType();
extern "C" void func_00288DA0();
extern "C" void func_002891D0();
extern "C" void func_00289990();
extern "C" void func_00289C80();
extern "C" void func_0028A430();
extern "C" void func_0028A470();
extern "C" void func_0028A4B0();
extern "C" void func_0028A5C0();
extern "C" void func_0033CCA0();
extern "C" void GuiScreen_Update();
extern "C" void GuiScreen_Sleep();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DD120[];
void* func_0033D430(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00288D40(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD120);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD120[28] = { (void*)0x0, (void*)0x0, (void*)func_00288D40, (void*)func_0028A5C0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0028A4B0, (void*)GuiScreen_Sleep, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00289990, (void*)func_0041E470, (void*)func_0041E230, (void*)GuiScreen_Update, (void*)func_00289C80, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00288DA0, (void*)GuiAccountLogin_IsType, (void*)func_002891D0, (void*)func_0033CCA0, (void*)func_0028A470, (void*)func_0028A430, (void*)0x0 };
