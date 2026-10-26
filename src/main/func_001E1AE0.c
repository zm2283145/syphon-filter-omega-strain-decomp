#pragma cplusplus on
#include "types.h"
#include "vtable_base_dtor.h"
extern "C" {
extern "C" void ContactEvent_Clone();
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern void * const D_004DAD20[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cGameEventMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAD20);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAD20[8] = { (void*)0x0, (void*)0x0, (void*)cGameEventMsg_dtor, (void*)ContactEvent_Clone, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
