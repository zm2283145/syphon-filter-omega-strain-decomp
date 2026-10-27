/*
 * SFOGame/Source/gameSound: 1 file, 001C9EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C9EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Sound manager receiver constructor.
 */

#include "types.h"
#include "gameSound_types.h"

/* SoundMgr vtable */
extern void cGameSound_HandleMessage();
extern void cSystem_ScriptGetObjectId();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void cGameSound_dtor();
extern void cSystem_getSOBJClassId();
extern void cSystem_ScriptHandleMessage();
void * const D_004DACB0[16] = { (void*)0x0, (void*)0x0, (void*)cGameSound_dtor, (void*)cGameSound_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
/* receiver registration data */
extern char D_004F2CC0[];
extern void* cSystem_ctor(void* self, void* info);
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern void* cGameSound_tSndFxPlayList_dtor(void* channel, int flags);
extern void* cGameSound_tSndFxPlayList_ctor(void* channel);

SoundMgr* cGameSound_ctor(SoundMgr* self) {
    cSystem_ctor(self, D_004F2CC0);
    self->vtable = ((char*)D_004DACB0);
    __construct_array(self->channels, cGameSound_tSndFxPlayList_ctor, cGameSound_tSndFxPlayList_dtor, sizeof(SoundChannel), 50);
    self->unk54A8 = 0;
    self->unk54AC = 0;
    self->unk54B0 = 0;
    self->unk20 = 0;
    return self;
}
static inline void merge_flush_func_001C9EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C9EA0 */
