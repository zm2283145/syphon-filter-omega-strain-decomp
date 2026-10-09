/*
 * Matched functions (byte-identical with the retail executable).
 * Receiver base-class constructor.
 */

#include "types.h"
#include "system_types.h"

extern char D_004DFDE0[];   /* Receiver vtable */

/* Initializes the Receiver base fields; owner is stored at +8. */
Receiver* Receiver_Construct(Receiver* self, void* owner) {
    self->vtable = D_004DFDE0;
    self->magic = RECEIVER_MAGIC;
    self->owner = owner;
    self->unk0C = -1;
    self->unk10 = -1;
    self->enabled = 1;
    self->unk18 = 0;
    return self;
}
