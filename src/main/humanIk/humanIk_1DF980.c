#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void func_001DF9E0(void); void operator_delete(void* p); }
extern "C" void* func_001DF980(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array(self, (void*)func_001DF9E0, 0x100, 0x15);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}