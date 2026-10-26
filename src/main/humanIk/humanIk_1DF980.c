#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void cBoneIk_dtor(void); void operator_delete(void* p); }
extern "C" void* cArray_FixedSize_cBoneIk_21_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array(self, (void*)cBoneIk_dtor, 0x100, 0x15);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}