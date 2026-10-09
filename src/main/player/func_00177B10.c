/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern void Component_BaseInit(void* self);
extern char D_004D9CF0[];  /* player component class table */
extern void InputState_Ctor(PlayerInputState* input);

PlayerComponent* PlayerComponent_Construct(PlayerComponent* self) {
    Component_BaseInit(self);
    self->vtable = D_004D9CF0;
    InputState_Ctor(&self->input);
    self->unk1A0 = 0;
    self->unk1C0 = 0;
    self->unk1B4 = 0;
    self->unk1B0 = 0;
    self->unk1A8 = 0.0f;
    self->unk1AC = 0.0f;
    self->unk1BC = 0;
    self->unk1B8 = -1;
    self->unk1A4 = 0;
    return self;
}
