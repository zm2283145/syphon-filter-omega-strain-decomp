#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cPriorityQueueItem_cNodeIndex_dtor();
extern void * const D_004D9700[];
extern void * const D_004D9710[];
extern "C" char D_004D9720[];
extern "C" VtableChainObject* cNodeIndex_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9710);
        if (self) {
            self->vtable = ((char*)D_004D9700);
            if (self)
                self->vtable = D_004D9720;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9700[4] = { (void*)0x0, (void*)0x0, (void*)cPriorityQueueItem_cNodeIndex_dtor, (void*)0x0 };
void * const D_004D9710[4] = { (void*)0x0, (void*)0x0, (void*)cNodeIndex_dtor, (void*)0x0 };
