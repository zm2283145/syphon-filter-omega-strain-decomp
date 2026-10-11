#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* allocation);
extern "C" char D_004E0060[];
extern "C" char D_004E0080[];
struct VC_003D18F0 { char pad[0x10]; void* vtable; };
extern "C" VC_003D18F0* func_003D18F0(VC_003D18F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0060;
        if (self)
            self->vtable = D_004E0080;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}