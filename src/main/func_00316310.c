#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void cMessage_getSOBJClassId();
extern "C" void cNetScoreMsg_Clone();
extern "C" void cNetScoreMsg_Pack();
extern void * const D_004DE5D0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cNetScoreMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE5D0);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE5D0[8] = { (void*)0x0, (void*)0x0, (void*)cNetScoreMsg_dtor, (void*)cNetScoreMsg_Clone, (void*)cNetScoreMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
