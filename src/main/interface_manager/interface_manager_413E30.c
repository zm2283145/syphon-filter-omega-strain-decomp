#pragma cplusplus on
#include "types.h"
extern "C" { void cInterfaceManager_Reset(void* self); void cInterfaceManager_Entry_dtor(void); void __destroy_array(void* p, void* dtor, int size, int n); void operator_delete(void* p); }
extern "C" void* InterfaceMgr_dtor(void* self, short deleteFlag)
{
    if (self) {
        cInterfaceManager_Reset(self);
        __destroy_array(self, (void*)cInterfaceManager_Entry_dtor, 0x18, 0x14);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}