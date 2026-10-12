#pragma cplusplus on
#include "types.h"
#include "vtable_chain_dtor.h"
extern "C" void func_003B4630();
extern void * const D_004DFC50[];
extern "C" VtableChainObject* func_001F2A00(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC50);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC50[8] = { (void*)0x0, (void*)0x0, (void*)func_001F2A00, (void*)0x0, (void*)func_003B4630, (void*)0x0, (void*)0x0, (void*)0x0 };
