#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_002A9660();
extern "C" void func_002A9670();
extern "C" void func_002A97E0();
extern "C" void func_002A97F0();
extern "C" void func_002A98D0();
extern "C" void func_002A9B50();
extern "C" void func_002A9BA0();
extern "C" void func_002A9FE0();
extern "C" void func_0033CCA0();
extern "C" void func_0033D310();
extern "C" void func_0033D360();
extern "C" void func_0033D3A0();
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
extern void * const D_004DDAF0[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O2A95F0 { void* vtable; char pad[0x9C]; char member[4]; };
extern "C" O2A95F0* func_002A95F0(O2A95F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DDAF0);
        func_0044F970(self->member, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDAF0[28] = { (void*)0x0, (void*)0x0, (void*)func_002A95F0, (void*)func_002A9FE0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0033D3A0, (void*)func_0033D360, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_002A98D0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0033D310, (void*)func_002A97F0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002A9660, (void*)func_002A9670, (void*)func_002A97E0, (void*)func_0033CCA0, (void*)func_002A9BA0, (void*)func_002A9B50, (void*)0x0 };
