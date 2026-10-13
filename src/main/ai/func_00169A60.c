#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void NpcAlert_SoundEvent();
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const D_004D9810[];
void* Receiver_Destruct(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00169A60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9810);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9810[16] = { (void*)0x0, (void*)0x0, (void*)func_00169A60, (void*)NpcAlert_SoundEvent, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
