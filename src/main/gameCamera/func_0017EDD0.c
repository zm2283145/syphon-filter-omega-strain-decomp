#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_004DA440[];
extern "C" void func_0017D270();
extern "C" void func_0017D330();
extern "C" void func_0017D5A0();
extern "C" void func_0017EE30();
extern "C" void func_00180B60();
void * const D_004DA350[12] = { (void*)0x0, (void*)0x0, (void*)func_0017EE30, (void*)func_00180B60, (void*)0x0, (void*)0x0, (void*)func_0017D5A0, (void*)func_0017D330, (void*)func_0017D270, (void*)0x0, (void*)0x0, (void*)0x0 };
extern "C" VtableChainObject* func_0017EDD0(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = D_004DA440;
        if (self)
            self->vtable = ((char*)D_004DA350);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
