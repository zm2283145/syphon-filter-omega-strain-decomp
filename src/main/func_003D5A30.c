#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void func_003D5AA0(void); void operator_delete(void* p); }
extern "C" void* func_003D5A30(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array((char*)self + 0x10, (void*)func_003D5AA0, 0x30, 6);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}