#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiOnlineOfflineSelect_IsType();
extern "C" void func_002A0180();
extern "C" void func_002A01C0();
extern "C" void func_002A0380();
extern "C" void func_002A05B0();
extern "C" void func_002A06C0();
extern "C" void func_002A0970();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F210();
extern void * const D_004DD6B0[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" VtableObject* func_002A0120(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD6B0);
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD6B0[24] = { (void*)0x0, (void*)0x0, (void*)func_002A0120, (void*)func_002A0970, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_002A06C0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_002A0380, (void*)func_0041E470, (void*)func_0041E230, (void*)func_002A05B0, (void*)func_002A01C0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002A0180, (void*)GuiOnlineOfflineSelect_IsType, (void*)0x0 };
