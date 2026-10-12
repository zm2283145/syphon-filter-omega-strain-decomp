#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void SkaClip_GetGroupingPair();
extern "C" void SkaClip_Submit();
extern void * const D_004DFC30[];
extern "C" char D_004DFC50[];
extern "C" VtableChainObject* func_003B28F0(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC30);
        if (self)
            self->vtable = D_004DFC50;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC30[8] = { (void*)0x0, (void*)0x0, (void*)func_003B28F0, (void*)SkaClip_Submit, (void*)SkaClip_GetGroupingPair, (void*)0x0, (void*)0x0, (void*)0x0 };
