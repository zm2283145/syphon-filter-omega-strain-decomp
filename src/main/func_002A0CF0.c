#pragma cplusplus on
#include "types.h"
extern "C" {
extern char D_004DD730[];
void* func_0044F970(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O002A0CF0 { void* vtable; char pad[0x84]; char m0[0x1C]; char m1[0x1C]; char m2[4]; };
extern "C" O002A0CF0* func_002A0CF0(O002A0CF0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DD730;
        func_0044F970(self->m2, -1);
        func_0044F970(self->m1, -1);
        func_0044F970(self->m0, -1);
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}