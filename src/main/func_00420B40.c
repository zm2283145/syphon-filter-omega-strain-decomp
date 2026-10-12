#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_0041BE50();
extern "C" void func_0041C150();
extern "C" void func_0041C310();
extern "C" void func_0041C560();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E3B0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_00420BA0();
extern "C" void func_00420BB0();
extern "C" void func_00420BE0();
extern "C" void func_00420C20();
extern "C" void func_00420C90();
extern void * const D_004E0C00[];
void* func_0041C6A0(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00420B40(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0C00);
        func_0041C6A0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0C00[24] = { (void*)0x0, (void*)0x0, (void*)func_00420B40, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00420BE0, (void*)func_0041C310, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00420C90, (void*)func_0041C150, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_00420C20, (void*)func_0041C560, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00420BA0, (void*)func_00420BB0, (void*)func_0041BE50 };
