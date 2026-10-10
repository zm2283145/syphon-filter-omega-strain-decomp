/*
 * Matched functions (byte-identical with the retail executable).
 * Sound manager receiver constructor.
 */

#include "types.h"
#include "gameSound_types.h"

extern char D_004DACB0[]; /* SoundMgr vtable */
extern char D_004F2CC0[]; /* receiver registration data */
extern void* Receiver_Construct(void* self, void* info);
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern void* func_001C9F10(void* channel, int flags);
extern void* func_001C9F80(void* channel);

SoundMgr* SoundMgr_Construct(SoundMgr* self) {
    Receiver_Construct(self, D_004F2CC0);
    self->vtable = D_004DACB0;
    __construct_array(self->channels, func_001C9F80, func_001C9F10, sizeof(SoundChannel), 50);
    self->unk54A8 = 0;
    self->unk54AC = 0;
    self->unk54B0 = 0;
    self->unk20 = 0;
    return self;
}
