#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293950();
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
extern "C" void func_00456E60();
extern "C" void func_00456ED0();
extern "C" void func_00456F40();
extern "C" void func_00456F90();
extern "C" void func_004574D0();
extern "C" void func_004574E0();
extern void * const D_004E1490[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00457470(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1490);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1490[24] = { (void*)0x0, (void*)0x0, (void*)func_00457470, (void*)func_00456F90, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00456ED0, (void*)func_00456E60, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00456F40, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_004574D0, (void*)func_004574E0, (void*)0x0 };
