#pragma cplusplus on
#include "types.h"
extern "C" { void func_004139C0(void* self); void func_00413EA0(void); void __destroy_array(void* p, void* dtor, int size, int n); void operator_delete(void* p); }
extern "C" void* func_00413E30(void* self, short deleteFlag)
{
    if (self) {
        func_004139C0(self);
        __destroy_array(self, (void*)func_00413EA0, 0x18, 0x14);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}