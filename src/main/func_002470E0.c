#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMenuChoiceMsg_v01();
extern "C" void cMenuChoiceMsg_v03();
extern void * const D_004DC330[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cMenuChoiceMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC330);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC330[8] = { (void*)0x0, (void*)0x0, (void*)cMenuChoiceMsg_dtor, (void*)cMenuChoiceMsg_v01, (void*)Event_PackHeader, (void*)cMenuChoiceMsg_v03, (void*)0x0, (void*)0x0 };
