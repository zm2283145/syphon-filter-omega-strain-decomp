#pragma cplusplus on
#include "types.h"
extern "C" {
extern char D_004DDAF0[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O2A95F0 { void* vtable; char pad[0x9C]; char member[4]; };
extern "C" O2A95F0* func_002A95F0(O2A95F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DDAF0;
        func_0044F970(self->member, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}