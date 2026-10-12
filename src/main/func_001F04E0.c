#pragma cplusplus on
#include "types.h"
#include "vtable_base_dtor.h"
extern "C" {
extern "C" void SkaClip_GetGroupingPair();
extern "C" void func_003B0A50();
extern void * const D_004DFC10[];
void* func_003B28F0(void* self, short deleteFlag);
}
extern "C" VtableObject* func_001F04E0(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC10);
        func_003B28F0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC10[8] = { (void*)0x0, (void*)0x0, (void*)func_001F04E0, (void*)func_003B0A50, (void*)SkaClip_GetGroupingPair, (void*)0x0, (void*)0x0, (void*)0x0 };
