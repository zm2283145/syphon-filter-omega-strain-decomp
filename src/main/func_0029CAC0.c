#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void GuiOnlineConnect_GetClassName();
extern "C" void func_00293890();
extern "C" void func_0029CB60();
extern "C" void func_0029CB90();
extern "C" void func_0029CBA0();
extern "C" void func_0029E1A0();
extern "C" void func_0029E440();
extern "C" void func_0029E8C0();
extern "C" void func_0029ECD0();
extern "C" void func_0029ED40();
extern "C" void func_0029EF30();
extern "C" void func_0029EF90();
extern "C" void func_0033CCA0();
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
extern "C" void func_0041F210();
extern void * const D_004DD620[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O0029CAC0 { void* vtable; char pad[0x94]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O0029CAC0* func_0029CAC0(O0029CAC0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD620);
        func_0044F970(self->m2, -1);
        func_0044F970(self->m1, -1);
        func_0044F970(self->m0, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD620[28] = { (void*)0x0, (void*)0x0, (void*)func_0029CAC0, (void*)func_0029EF90, (void*)func_0029EF30, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0029ED40, (void*)func_0029ECD0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0029E8C0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0029E1A0, (void*)func_0029E440, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)GuiOnlineConnect_GetClassName, (void*)func_0029CB60, (void*)func_00293890, (void*)func_0033CCA0, (void*)func_0029CB90, (void*)func_0029CBA0, (void*)0x0 };
