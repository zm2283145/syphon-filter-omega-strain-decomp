#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* allocation);
extern "C" void func_003D1950();
extern "C" void func_003D1960();
extern void * const D_004E0060[];
extern const unsigned int D_004E0080[];
struct VC_003D18F0 { char pad[0x10]; void* vtable; };
extern "C" VC_003D18F0* func_003D18F0(VC_003D18F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0060);
        if (self)
            self->vtable = ((char*)D_004E0080);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0060[8] = { (void*)0x0, (void*)0x0, (void*)func_003D1960, (void*)func_003D1950, (void*)func_003D18F0, (void*)0x0, (void*)0x0, (void*)0x0 };
const unsigned int D_004E0080[4] = { 0x0, 0x0, 0x0, 0x0 };
