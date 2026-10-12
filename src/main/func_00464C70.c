#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_00414BE0();
extern "C" void func_00414F00();
extern "C" void func_00415170();
extern "C" void func_00415BB0();
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
extern "C" void func_0041EFA0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_0041F210();
extern "C" void func_00464CE0();
extern "C" void func_00464CF0();
extern "C" void func_00464D20();
extern "C" void func_004650C0();
extern "C" void func_004653B0();
extern void * const D_004E1940[];
extern char D_004E1A20[];
void* func_00415F00(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_00464C70(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E1940);
        if (self) {
            self->vtable = D_004E1A20;
            func_00415F00(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E1940[28] = { (void*)0x0, (void*)0x0, (void*)func_00464C70, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00415170, (void*)func_0041E470, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_004653B0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00464CE0, (void*)func_00464CF0, (void*)func_00415BB0, (void*)func_00464D20, (void*)func_00414F00, (void*)func_00414BE0, (void*)func_004650C0 };
