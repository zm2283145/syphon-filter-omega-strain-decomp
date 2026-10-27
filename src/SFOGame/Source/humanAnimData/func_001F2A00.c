#pragma cplusplus on
#include "types.h"
#include "vtable_chain_dtor.h"
extern "C" void cSkaNode_PlaybackGroupId();
extern void * const D_004DFC50[];
extern "C" VtableChainObject* cSkaNode_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC50);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC50[8] = { (void*)0x0, (void*)0x0, (void*)cSkaNode_dtor, (void*)0x0, (void*)cSkaNode_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
