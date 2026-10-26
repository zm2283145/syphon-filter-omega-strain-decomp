#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void cShadowMan_tSource_dtor(void); void operator_delete(void* p); }
extern "C" void* cShadowMan_tCaster_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array((char*)self + 0x10, (void*)cShadowMan_tSource_dtor, 0x30, 6);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}