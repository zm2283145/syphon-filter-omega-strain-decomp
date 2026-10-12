#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_00497F50[];
extern "C" void std_exception_what();
extern void * const D_004D9040[];
extern "C" VtableChainObject* std_exception_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9040);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9040[4] = { (void*)D_00497F50, (void*)0x0, (void*)std_exception_dtor, (void*)std_exception_what };
