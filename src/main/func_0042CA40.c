#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Message_GetScriptTypeKey();
extern "C" void cNetActivateAndControlMsg_v01();
extern "C" void cNetActivateAndControlMsg_v02();
extern void * const D_004E0EA0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cNetActivateAndControlMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0EA0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0EA0[8] = { (void*)0x0, (void*)0x0, (void*)cNetActivateAndControlMsg_dtor, (void*)cNetActivateAndControlMsg_v01, (void*)cNetActivateAndControlMsg_v02, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
