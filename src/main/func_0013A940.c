#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cLosResultReadyMessage_Clone();
extern void * const D_004D91C0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cLosResultReadyMessage_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D91C0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D91C0[8] = { (void*)0x0, (void*)0x0, (void*)cLosResultReadyMessage_dtor, (void*)cLosResultReadyMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
