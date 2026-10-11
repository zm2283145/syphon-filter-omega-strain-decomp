#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void func_0018A210(void); void operator_delete(void* p); }
extern "C" void* func_0018A040(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array(self, (void*)func_0018A210, 8, 7);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}