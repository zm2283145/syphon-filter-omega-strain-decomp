#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern void * const D_004DFAA0[];
extern "C" VtableChainObject* cParticleDefinition_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFAA0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFAA0[6] = { (void*)0x0, (void*)0x0, (void*)cParticleDefinition_dtor, (void*)0x0, (void*)0x0, (void*)0x0 };
