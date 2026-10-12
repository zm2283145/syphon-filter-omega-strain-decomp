#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void func_00294210();
extern "C" void func_00294220();
extern "C" void func_00294250();
extern "C" void func_00295430();
extern "C" void func_00295640();
extern "C" void func_002958B0();
extern "C" void func_00296660();
extern "C" void func_00297350();
extern "C" void func_002973B0();
extern "C" void func_00297B10();
extern "C" void func_00297C10();
extern "C" void func_0033CCA0();
extern "C" void func_0033D360();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DD4F0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_00138350(void* self, short deleteFlag);
void func_0033D430(void* self, int flags);
void operator_delete(void* p);
}
struct O294190 { void* vtable; char pad[0x200]; char items[0x11][0xC]; };
extern "C" O294190* func_00294190(O294190* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD4F0);
        __destroy_array(self->items, (void*)func_00138350, 0xC, 0x11);
        func_0033D430(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DD4F0[28] = { (void*)0x0, (void*)0x0, (void*)func_00294190, (void*)func_00297C10, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00297B10, (void*)func_0033D360, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00295640, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00296660, (void*)func_002958B0, (void*)func_0041F210, (void*)func_00294250, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00294210, (void*)func_00294220, (void*)func_00295430, (void*)func_0033CCA0, (void*)func_002973B0, (void*)func_00297350, (void*)0x0 };
