#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_00147BA0();
extern void * const D_004D92C0[];
extern char D_004D92A0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_00140DA0(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D92C0);
        if (self) {
            self->vtable = D_004D92A0;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D92C0[8] = { (void*)0x0, (void*)0x0, (void*)func_00140DA0, (void*)func_00147BA0, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
