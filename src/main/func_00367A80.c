#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiObjectives_GetClassName();
extern "C" void func_00367AF0();
extern "C" void func_003680A0();
extern "C" void func_00368300();
extern "C" void func_00368620();
extern "C" void func_00368760();
extern "C" void func_003688C0();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DF5C0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00367A80(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF5C0);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF5C0[24] = { (void*)0x0, (void*)0x0, (void*)func_00367A80, (void*)func_003688C0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00368760, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00368300, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00368620, (void*)func_003680A0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiObjectives_GetClassName, (void*)func_00367AF0, (void*)0x0 };
