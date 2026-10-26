#pragma cplusplus on
#include "vt4_dtor.h"

extern "C" {
extern "C" void HudRadar_Update();
extern "C" void cHudTargetsObserver_dtor();
extern "C" void cHudTargetsObserver_Update();
extern "C" void cHudTargetsObserver_TargetAdded();
extern "C" void cHudTargetsObserver_TargetRemoved();
extern void * const D_004DC930[];
extern void * const D_004DC950[];
}
extern "C" Vt4Object* cHudRadar_dtor(Vt4Object* self, short deleteFlag) {
    if (self) {
        self->vtable = ((char*)D_004DC950);
        if (self) self->vtable = ((char*)D_004DC930);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DC930[8] = { (void*)0x0, (void*)0x0, (void*)cHudTargetsObserver_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudTargetsObserver_dtor, (void*)0x0, (void*)0x0 };
void * const D_004DC950[8] = { (void*)0x0, (void*)0x0, (void*)HudRadar_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudRadar_dtor, (void*)0x0, (void*)0x0 };
