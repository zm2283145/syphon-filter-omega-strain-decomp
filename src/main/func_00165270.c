#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void func_00165310();
extern "C" void func_00165370();
extern void * const D_004D9778[];
extern void * const D_004D9788[];
extern void * const D_004D9798[];
extern "C" VtableChainObject* func_00165270(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9798);
        if (self) {
            self->vtable = ((char*)D_004D9788);
            if (self)
                self->vtable = ((char*)D_004D9778);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9778[3] = { (void*)0x0, (void*)0x0, (void*)func_00165370 };
void * const D_004D9788[3] = { (void*)0x0, (void*)0x0, (void*)func_00165310 };
void * const D_004D9798[3] = { (void*)0x0, (void*)0x0, (void*)func_00165270 };
