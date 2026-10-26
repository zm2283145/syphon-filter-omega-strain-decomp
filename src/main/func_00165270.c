#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cPriorityQueueItem_cPathCell_dtor();
extern "C" void cParticleListItem_cPathCell_dtor();
extern void * const D_004D9778[];
extern void * const D_004D9788[];
extern void * const D_004D9798[];
extern "C" VtableChainObject* cPathCell_dtor(VtableChainObject* self,
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
void * const D_004D9778[3] = { (void*)0x0, (void*)0x0, (void*)cParticleListItem_cPathCell_dtor };
void * const D_004D9788[3] = { (void*)0x0, (void*)0x0, (void*)cPriorityQueueItem_cPathCell_dtor };
void * const D_004D9798[3] = { (void*)0x0, (void*)0x0, (void*)cPathCell_dtor };
