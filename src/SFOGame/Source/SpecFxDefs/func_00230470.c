#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void cMessage_getSOBJClassId();
extern "C" void cNetSpawnLightMsg_Clone();
extern "C" void cNetSpawnLightMsg_Pack();
extern "C" void cNetSpawnLightMsg_GetMsgId();
extern "C" void cNetMsg_Pack();
extern void * const D_004DBAC0[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cNetSpawnLightMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DBAC0);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DBAC0[8] = { (void*)0x0, (void*)0x0, (void*)cNetSpawnLightMsg_dtor, (void*)cNetSpawnLightMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cNetSpawnLightMsg_Pack, (void*)cNetSpawnLightMsg_GetMsgId };
