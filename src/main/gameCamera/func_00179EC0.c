#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cHumanSeenMsg_v01();
extern "C" void cHumanSeenMsg_v03();
extern "C" void cHumanSeenMsg_v04();
extern "C" void cHumanSeenMsg_v05();
extern "C" void func_002823E0();
extern void * const D_004DA310[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cHumanSeenMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA310);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA310[8] = { (void*)0x0, (void*)0x0, (void*)cHumanSeenMsg_dtor, (void*)cHumanSeenMsg_v01, (void*)func_002823E0, (void*)cHumanSeenMsg_v03, (void*)cHumanSeenMsg_v04, (void*)cHumanSeenMsg_v05 };
