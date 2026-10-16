#pragma cplusplus on
#include "vt4_dtor.h"

extern "C" {
extern "C" void HudRadar_Update();
extern "C" void func_00261AF0();
extern "C" void func_00261B40();
extern "C" void func_00261B50();
extern "C" void func_00261B60();
extern void * const D_004DC930[];
extern void * const D_004DC950[];
}
extern "C" Vt4Object* func_00261950(Vt4Object* self, short deleteFlag) {
    if (self) {
        self->vtable = ((char*)D_004DC950);
        if (self) self->vtable = ((char*)D_004DC930);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DC930[8] = { (void*)0x0, (void*)0x0, (void*)func_00261B40, (void*)func_00261B50, (void*)func_00261B60, (void*)func_00261AF0, (void*)0x0, (void*)0x0 };
void * const D_004DC950[8] = { (void*)0x0, (void*)0x0, (void*)HudRadar_Update, (void*)func_00261B50, (void*)func_00261B60, (void*)func_00261950, (void*)0x0, (void*)0x0 };
