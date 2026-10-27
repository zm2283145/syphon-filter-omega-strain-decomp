#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void cTimerExpiredMsg_v01();
extern "C" void cTimerExpiredMsg_v03();
extern "C" void cTimerExpiredMsg_v04();
extern "C" void cTimerExpiredMsg_v05();
extern "C" void cNetMsg_Pack();
extern void * const D_004DBA00[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cTimerExpiredMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DBA00);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DBA00[8] = { (void*)0x0, (void*)0x0, (void*)cTimerExpiredMsg_dtor, (void*)cTimerExpiredMsg_v01, (void*)cNetMsg_Pack, (void*)cTimerExpiredMsg_v03, (void*)cTimerExpiredMsg_v04, (void*)cTimerExpiredMsg_v05 };
