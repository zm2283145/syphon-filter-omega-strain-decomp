#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void func_00397A80();
extern "C" void func_00397A90();
extern "C" void func_00397AB0();
extern "C" void func_00398590();
extern "C" void func_00398B20();
extern void * const D_004DFA80[];
extern "C" char D_004DFB50[];
extern "C" char D_004DFAD8[];
extern "C" VtableChainObject* func_00397A10(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFA80);
        if (self) {
            self->vtable = D_004DFB50;
            if (self)
                self->vtable = D_004DFAD8;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFA80[8] = { (void*)0x0, (void*)0x0, (void*)func_00397A10, (void*)func_00398590, (void*)func_00398B20, (void*)func_00397A80, (void*)func_00397AB0, (void*)func_00397A90 };
