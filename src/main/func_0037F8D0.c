#pragma cplusplus on

#include "types.h"

/* Deleting destructor: list member at +0x1108, array of 6 20-byte elements at +0x1068. */
extern "C" {
void* std_list_tDataDelRec_dtor(void* self, short flags);
void* cUserFrameEnv_dtor(void* self, short flags);
void __destroy_array(void* array, void* dtor, unsigned int size, unsigned int count);
void operator_delete(void* allocation);
}
extern "C" void* XLib_dtor(void* self, short deleteFlag)
{
    if (self) {
        char* l = (char*)self + 0x1108;
        if (l)
            std_list_tDataDelRec_dtor(l, 0);
        __destroy_array((char*)self + 0x1068, (void*)cUserFrameEnv_dtor, 0x14, 6);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}