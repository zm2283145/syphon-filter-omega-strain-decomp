#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void AngleCurve_PreUpdate();
extern "C" void AngleCurve_UpdateRate();
extern "C" void func_001B87E0();
extern "C" void func_001B88A0();
extern "C" void func_001B88B0();
extern "C" void func_001B8AC0();
extern void * const D_004DA7D0[];
extern "C" char D_004DA380[];
extern "C" VtableChainObject* func_001B5E70(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA7D0);
        if (self)
            self->vtable = D_004DA380;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA7D0[12] = { (void*)0x0, (void*)0x0, (void*)func_001B5E70, (void*)func_001B87E0, (void*)func_001B88A0, (void*)func_001B88B0, (void*)AngleCurve_PreUpdate, (void*)func_001B8AC0, (void*)AngleCurve_UpdateRate, (void*)0x0, (void*)0x0, (void*)0x0 };
