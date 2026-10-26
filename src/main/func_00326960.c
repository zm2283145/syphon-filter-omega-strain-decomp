#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void Message_GetScriptTypeKey();
extern "C" void cEnableSuperJumpMsg_v01();
extern "C" void cEnableSuperJumpMsg_v04();
extern "C" void cEnableSuperJumpMsg_v05();
extern "C" void cNetMsg_Pack();
extern void * const D_004DE6F0[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cEnableSuperJumpMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE6F0);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE6F0[8] = { (void*)0x0, (void*)0x0, (void*)cEnableSuperJumpMsg_dtor, (void*)cEnableSuperJumpMsg_v01, (void*)cNetMsg_Pack, (void*)Message_GetScriptTypeKey, (void*)cEnableSuperJumpMsg_v04, (void*)cEnableSuperJumpMsg_v05 };
