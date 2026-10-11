#pragma cplusplus on

#include "types.h"

/* Deleting destructor: list member at +0x1108, array of 6 20-byte elements at +0x1068. */
extern "C" {
void* func_0037F950(void* self, short flags);
void* func_003BB2F0(void* self, short flags);
void __destroy_array(void* array, void* dtor, unsigned int size, unsigned int count);
void operator_delete(void* allocation);
}
extern "C" void* func_0037F8D0(void* self, short deleteFlag)
{
    if (self) {
        char* l = (char*)self + 0x1108;
        if (l)
            func_0037F950(l, 0);
        __destroy_array((char*)self + 0x1068, (void*)func_003BB2F0, 0x14, 6);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}