/*
 * Matched functions (byte-identical with the retail executable).
 * Sound manager receiver constructor.
 */

#include "types.h"
#include "gameSound_types.h"

/* SoundMgr vtable */
extern void SoundMgr_OnMessage();
extern void GObj_GetID();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void SoundMgr_dtor();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
void * const D_004DACB0[16] = { (void*)0x0, (void*)0x0, (void*)SoundMgr_dtor, (void*)SoundMgr_OnMessage, (void*)GObj_GetID, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
/* receiver registration data */
extern char D_004F2CC0[];
extern void* Receiver_Construct(void* self, void* info);
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern void* SoundSlot_Dtor(void* channel, int flags);
extern void* SoundSlot_Ctor(void* channel);

SoundMgr* SoundMgr_Construct(SoundMgr* self) {
    Receiver_Construct(self, D_004F2CC0);
    self->vtable = ((char*)D_004DACB0);
    __construct_array(self->channels, SoundSlot_Ctor, SoundSlot_Dtor, sizeof(SoundChannel), 50);
    self->unk54A8 = 0;
    self->unk54AC = 0;
    self->unk54B0 = 0;
    self->unk20 = 0;
    return self;
}
