#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWeaponStats_IsType();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E3B0();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_004235C0();
extern "C" void func_004235E0();
extern "C" void func_00423610();
extern "C" void func_00423660();
extern "C" void func_00423670();
extern "C" void func_004249D0();
extern "C" void func_00424A10();
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
void * const D_004E1350[32] = { (void*)0x0, (void*)0x0, (void*)func_00457280, (void*)func_00455B60, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_004261D0, (void*)func_00426100, (void*)func_00424A10, (void*)func_004249D0, (void*)func_004557C0, (void*)func_00423670, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_004572E0, (void*)GuiWeaponStats_IsType, (void*)func_00426350, (void*)func_00423660, (void*)func_00423610, (void*)func_00455AE0, (void*)func_004235E0, (void*)func_004235C0, (void*)0x0, (void*)0x0, (void*)0x0 };
