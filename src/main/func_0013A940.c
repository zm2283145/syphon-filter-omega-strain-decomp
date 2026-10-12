#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_0013B190();
extern void * const D_004D91C0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0013A940(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D91C0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D91C0[8] = { (void*)0x0, (void*)0x0, (void*)func_0013A940, (void*)func_0013B190, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
