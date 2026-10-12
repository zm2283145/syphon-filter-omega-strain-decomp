#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_0041A0C0();
extern "C" void func_0041A0D0();
extern "C" void func_0041A450();
extern "C" void func_0041A8F0();
extern "C" void func_0041AA10();
extern "C" void func_0041AA80();
extern "C" void func_0041ACE0();
extern "C" void func_0041AD60();
extern "C" void func_0041C310();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern void * const D_004E0A40[];
void* func_0041C6A0(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0041A060(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0A40);
        func_0041C6A0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0A40[24] = { (void*)0x0, (void*)0x0, (void*)func_0041A060, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041AD60, (void*)func_0041C310, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0041AA80, (void*)func_0041A450, (void*)func_0041E230, (void*)func_0041A8F0, (void*)func_0041EF10, (void*)func_0041ACE0, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0041A0C0, (void*)func_0041A0D0, (void*)func_0041AA10 };
