#pragma cplusplus on

#include "types.h"

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void func_003AA320(void* self);
extern "C" void* func_003A62A0(void* self, short deleteFlag);

extern "C" void* func_003A6320(void* self, short deleteFlag)
{
    if (self) {
        func_003AA320(self);
        if (self)
            func_003A62A0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}