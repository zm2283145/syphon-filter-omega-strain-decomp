#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void cMessage_getSOBJClassId();
extern "C" void cNetActivateAndControlMsg_Clone();
extern "C" void cNetActivateAndControlMsg_Pack();
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
void * const D_004E0EA0[8] = { (void*)0x0, (void*)0x0, (void*)cNetActivateAndControlMsg_dtor, (void*)cNetActivateAndControlMsg_Clone, (void*)cNetActivateAndControlMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
