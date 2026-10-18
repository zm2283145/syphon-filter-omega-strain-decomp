/*
 * Matched functions (byte-identical with the retail executable).
 * Sound manager receiver constructor.
 */

#include "types.h"
#include "gameSound_types.h"

/* SoundMgr vtable */
extern void SoundMgr_OnMessage();
extern void GObj_GetID();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void func_001CA750();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
void * const D_004DACB0[16] = { (void*)0x0, (void*)0x0, (void*)func_001CA750, (void*)SoundMgr_OnMessage, (void*)GObj_GetID, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
/* receiver registration data */
extern char D_004F2CC0[];
extern void* Receiver_Construct(void* self, void* info);
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern void* func_001C9F10(void* channel, int flags);
extern void* SoundSlot_Ctor(void* channel);

SoundMgr* SoundMgr_Construct(SoundMgr* self) {
    Receiver_Construct(self, D_004F2CC0);
    self->vtable = ((char*)D_004DACB0);
    __construct_array(self->channels, SoundSlot_Ctor, func_001C9F10, sizeof(SoundChannel), 50);
    self->unk54A8 = 0;
    self->unk54AC = 0;
    self->unk54B0 = 0;
    self->unk20 = 0;
    return self;
}
