#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiFrontendCanvas_IsType();
extern "C" void func_00414BE0();
extern "C" void func_00415BB0();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041EFA0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_0041F210();
extern "C" void func_00465500();
extern "C" void func_00465570();
extern "C" void func_00465600();
extern "C" void func_00465610();
extern "C" void func_004657E0();
extern "C" void func_00465E80();
extern void * const D_004E19B0[];
extern char D_004E1A20[];
void* func_00415F00(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_00465E10(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E19B0);
        if (self) {
            self->vtable = D_004E1A20;
            func_00415F00(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E19B0[28] = { (void*)0x0, (void*)0x0, (void*)func_00465E10, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00465600, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00465610, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00465E80, (void*)GuiFrontendCanvas_IsType, (void*)func_00415BB0, (void*)func_00465500, (void*)func_00465570, (void*)func_00414BE0, (void*)func_004657E0 };
