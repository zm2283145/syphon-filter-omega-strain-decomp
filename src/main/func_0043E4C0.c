#pragma cplusplus on
#include "types.h"
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
extern "C" void func_0041EBF0();
extern "C" void func_0041EF10();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F210();
extern "C" void func_0043D720();
extern "C" void func_0043D730();
extern "C" void func_0043D8B0();
extern "C" void func_0043E0E0();
extern "C" void func_0043E2E0();
extern "C" void func_0043E330();
extern void * const D_004E1040[];
void func_0043DB80(void* self);
void func_0043E550(void* p, int flag);
void func_0041F370(void* self, int flag);
void operator_delete(void* p);
}
typedef struct { void* vt; char pad[0x6C]; char m70[0xC]; int x7C; } S_E4C0;
extern "C" S_E4C0* func_0043E4C0(S_E4C0* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004E1040);
        self->x7C = 0;
        func_0043DB80(self);
        {
            void* m = self->m70;
            if (m)
                func_0043E550(m, 0);
        }
        func_0041F370(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1040[24] = { (void*)0x0, (void*)0x0, (void*)func_0043E4C0, (void*)func_0043E330, (void*)func_0043E0E0, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0043E2E0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00293950, (void*)func_0043D8B0, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0043D720, (void*)func_0043D730, (void*)0x0 };
