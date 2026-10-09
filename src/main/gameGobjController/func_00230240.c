/*
 * Matched functions (byte-identical with the retail executable).
 * Base component constructor.
 */

#include "types.h"
#include "gameGobjController_types.h"

extern char D_004DBA20[];   /* component vtable */
extern int func_003EA630(Component* self);

Component* Component_BaseInit(Component* self) {
    func_003EA630(self);
    self->vtable = D_004DBA20;
    self->unk38 = 1.0f;
    self->unk3C = -1;
    self->unk40 = 0;
    return self;
}
