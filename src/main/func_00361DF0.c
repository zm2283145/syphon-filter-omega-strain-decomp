#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string members at +0x3C and +0x30. */
extern "C" {
void operator_delete(void* allocation);
void* func_00138B70(void* self, short deleteFlag);
}
extern "C" void* func_00361DF0(void* self, short deleteFlag)
{
    if (self) {
        char* a = (char*)self + 0x3C;
        if (a)
            func_00138B70(a, 0);
        char* b = (char*)self + 0x30;
        if (b)
            func_00138B70(b, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}