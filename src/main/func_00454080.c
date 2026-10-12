#pragma cplusplus on
#include "types.h"
extern "C" {
void func_0036E220(void* member, int flags);
void func_0041F370(void* self, int flags);
void operator_delete(void* allocation);
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EFA0();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern "C" void func_00454110();
extern "C" void func_00454120();
extern "C" void func_00454150();
extern "C" void func_00454380();
extern "C" void func_00454440();
extern "C" void func_00454880();
extern "C" void func_00454910();
extern "C" void func_00454A80();
extern void * const D_004E1290[];
}
struct TM454080 { void* vtable; char base[0x4C]; char payload[0x48]; char memberA[0x9C]; char memberB[4]; };
extern "C" TM454080* func_00454080(TM454080* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1290);
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1290[24] = { (void*)0x0, (void*)0x0, (void*)func_00454080, (void*)func_00454910, (void*)func_0041F090, (void*)func_0041F080, (void*)func_00454880, (void*)func_0041EFA0, (void*)func_00454A80, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00454150, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00454380, (void*)func_00454440, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00454110, (void*)func_00454120, (void*)0x0 };
