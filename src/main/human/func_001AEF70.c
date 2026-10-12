#pragma cplusplus on

#include "types.h"

/* Anim channel destructor, optionally delete (DEFINE_ANIM_CHANNEL_DTOR_DEEP of
 * anim_channel_dtor.h written out, so the unit can define the class vtable). */
extern "C" {
void func_001AEFE0();
void func_001B8E40();
void func_001B9030();
void AnimChannel_DirectDerivedZero();
void AnimChannel_PreUpdate();
void AnimChannel_ClampValue();
void AnimChannel_UpdateRate();
extern char D_004DA380[];
void operator_delete(void* allocation);
void* const D_004DA840[12] = { 0, 0, (void*)func_001AEFE0, (void*)func_001B8E40, (void*)func_001B9030,
    (void*)AnimChannel_DirectDerivedZero, (void*)AnimChannel_PreUpdate, (void*)AnimChannel_ClampValue,
    (void*)AnimChannel_UpdateRate, 0, 0, 0 };
}

struct AnimChannelObj {
    void* vtable;
};

extern "C" AnimChannelObj* func_001AEF70(AnimChannelObj* self, short deleteFlag)
{
    if (self) {
        if (self) {
            self->vtable = (void*)D_004DA840;
            if (self)
                self->vtable = D_004DA380;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
