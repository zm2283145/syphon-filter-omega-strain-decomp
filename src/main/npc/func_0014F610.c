#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cAIWeaponFiredMsg_v01();
extern "C" void cAIWeaponFiredMsg_v03();
extern "C" void cAIGOBJMsg_v02();
extern void * const D_004DCBF0[];
extern char D_004DCD70[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAIWeaponFiredMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DCBF0);
        if (self) {
            self->vtable = D_004DCD70;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DCBF0[8] = { (void*)0x0, (void*)0x0, (void*)cAIWeaponFiredMsg_dtor, (void*)cAIWeaponFiredMsg_v01, (void*)cAIGOBJMsg_v02, (void*)cAIWeaponFiredMsg_v03, (void*)0x0, (void*)0x0 };
