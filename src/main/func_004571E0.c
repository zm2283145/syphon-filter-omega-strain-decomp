#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
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
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_00454B10();
extern "C" void func_00455550();
extern "C" void func_00455610();
extern "C" void func_00457240();
extern "C" void func_00457250();
extern void * const D_004E12F0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_004571E0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E12F0);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E12F0[24] = { (void*)0x0, (void*)0x0, (void*)func_004571E0, (void*)func_00455610, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00455550, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00454B10, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00457240, (void*)func_00457250, (void*)0x0 };
