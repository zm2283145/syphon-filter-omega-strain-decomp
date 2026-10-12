#pragma cplusplus on
#include "types.h"
#include "vt8_chain_dtor.h"
extern "C" {
extern "C" void func_00177E20();
extern "C" void func_001C80B0();
extern void * const D_004DAC30[];
extern char D_004D9DE0[];
}
extern "C" Vt8Object* func_001C61A0(Vt8Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAC30);
        if (self)
            self->vtable = D_004D9DE0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAC30[8] = { (void*)0x0, (void*)0x0, (void*)func_001C61A0, (void*)func_00177E20, (void*)func_001C80B0, (void*)0x0, (void*)0x0, (void*)0x0 };
