#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_00316370();
extern "C" void func_00316600();
extern void * const D_004DE5D0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00316310(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE5D0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE5D0[8] = { (void*)0x0, (void*)0x0, (void*)func_00316310, (void*)func_00316370, (void*)func_00316600, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
