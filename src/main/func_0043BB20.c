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
extern "C" void func_0041EBF0();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_0043BB80();
extern "C" void func_0043BB90();
extern "C" void func_0043BDE0();
extern "C" void func_0043BE70();
extern void * const D_004E0F40[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0043BB20(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0F40);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0F40[24] = { (void*)0x0, (void*)0x0, (void*)func_0043BB20, (void*)func_0043BE70, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0043BDE0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0043BB80, (void*)func_0043BB90, (void*)0x0 };
