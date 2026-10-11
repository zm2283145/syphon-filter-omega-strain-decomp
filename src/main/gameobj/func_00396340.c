#pragma cplusplus on

#include "types.h"

/* Deleting destructor: member cleanup, then base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void func_00393380(void* self);
extern "C" void func_003965A0(void* self);
extern "C" void* func_003963B0(void* self, short deleteFlag);

extern "C" void* func_00396340(void* self, short deleteFlag)
{
    if (self) {
        if (self) {
            func_00393380(self);
            func_003965A0(self);
            func_003963B0(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}