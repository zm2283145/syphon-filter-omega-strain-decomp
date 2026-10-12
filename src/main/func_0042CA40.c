#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_0042CAA0();
extern "C" void func_0042CC40();
extern void * const D_004E0EA0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0042CA40(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0EA0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0EA0[8] = { (void*)0x0, (void*)0x0, (void*)func_0042CA40, (void*)func_0042CAA0, (void*)func_0042CC40, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
