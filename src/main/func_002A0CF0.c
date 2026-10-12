#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_00293890();
extern "C" void func_002A0D80();
extern "C" void func_002A0D90();
extern "C" void func_002A1140();
extern "C" void func_002A12F0();
extern "C" void func_002A1700();
extern "C" void func_002A1780();
extern "C" void func_0033CCA0();
extern "C" void func_0033D310();
extern "C" void func_0033D360();
extern "C" void func_0033D3A0();
extern "C" void func_0033D3F0();
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
extern void * const D_004DD730[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O002A0CF0 { void* vtable; char pad[0x84]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O002A0CF0* func_002A0CF0(O002A0CF0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD730);
        func_0044F970(self->m2, -1);
        func_0044F970(self->m1, -1);
        func_0044F970(self->m0, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD730[28] = { (void*)0x0, (void*)0x0, (void*)func_002A0CF0, (void*)func_0033D3F0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0033D3A0, (void*)func_0033D360, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_002A12F0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0033D310, (void*)func_002A1140, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002A0D80, (void*)func_002A0D90, (void*)func_00293890, (void*)func_0033CCA0, (void*)func_002A1780, (void*)func_002A1700, (void*)0x0 };
