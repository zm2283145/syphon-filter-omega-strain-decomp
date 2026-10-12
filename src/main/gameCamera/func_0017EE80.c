#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_004DAD70[];
extern "C" void func_0017F030();
void * const D_004DA330[8] = { (void*)0x0, (void*)0x0, (void*)func_0017F030, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern "C" VtableChainObject* func_0017EE80(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAD70;
        if (self)
            self->vtable = ((char*)D_004DA330);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
